#include <iostream>
#include <list> // It's an example to use list, instead of vector.
using std::cout;
using std::endl;
using std::list;
using std::string;

class YoutubeChannel { // Class name start from capital letters.
    // By default, everything is private, if no public or protected.
    // The public section should be first, followed by the protected and finally
    // the private section.
  public:
    // get and set methods start from small letters. All other methods start
    // from capital letters.
    YoutubeChannel(string name, string owner_name) { // No return type.
        name_ = name;
        owner_name_ = owner_name;
        subscriber_count_ = 0;
    }

    void Subscribe() { subscriber_count_++; }

    void Unsubscribe() {
        if (subscriber_count_ > 0)
            subscriber_count_--;
    }

    void PublishVideo(string title) {
        published_videos_titles_.push_back(title);
    }

    void GetInfo() { // Each word start from capital letters and no underlines
                     // in between.
        cout << "Name: " << name_ << endl;
        cout << "Owner: " << owner_name_ << endl;
        cout << "Subscriber Count: " << subscriber_count_ << endl;
        cout << "Video:" << endl;
        for (string video_title : published_videos_titles_) {
            cout << video_title << endl;
        }
        cout << endl;
    }

    // Keywords public, protected, private should be preceded by a blank line.
  protected: // Only protected and public elements are accessable by the derived
             // classes.
    string owner_name_; // Only use small letters and underlines between them.

  private:
    // private elements only accessable by its own class. NOT derived classes.
    string name_; // The underline is after the name.
    int subscriber_count_;
    list<string> published_videos_titles_;
}; // Don't miss ";".

class CookingYouTubeChannel : public YoutubeChannel {
  public: // Have NO access to private elements.
    CookingYouTubeChannel(string name, string owner_name)
        : YoutubeChannel(name, owner_name) {}

    void Practice() {
        // To have access to owner_name_, it should be protected or public in
        // the base class.
        cout << owner_name_ << " is practicing cooking!" << endl;
    }
};

int main() {
    YoutubeChannel ytChannel("CodeBeauty", "Saldina");
    ytChannel.PublishVideo("C++ for beginner");
    ytChannel.PublishVideo("HTML & CSS for beginners");
    ytChannel.PublishVideo("C++ OOP");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    ytChannel.GetInfo();

    CookingYouTubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
    cookingYtChannel.PublishVideo("Apple pie");
    cookingYtChannel.PublishVideo("Chocolate cake");
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    ytChannel.Unsubscribe();
    cookingYtChannel.GetInfo();
    cookingYtChannel.Practice();

    return 0;
}