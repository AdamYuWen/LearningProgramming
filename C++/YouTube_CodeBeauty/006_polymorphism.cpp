#include <iostream>
using std::cout;
using std::endl;
using std::string;

class YoutubeChannel {
  public:
    YoutubeChannel(string name, string owner_name) {
        name_ = name;
        owner_name_ = owner_name;
        subscriber_count_ = 0;
    }

    int get_subscriber_count() { return subscriber_count_; }

    void set_subscriber_count(int value) { subscriber_count_ = value; }

    // The function is in the base class.
    void Quality() {
        if (subscriber_count_ < 5) {
            cout << name_ << " => Bad Subscriber" << endl;
        } else {
            cout << name_ << " => Good Subscriber" << endl;
        }
    }

  protected:
    string owner_name_;

  private:
    string name_;
    int subscriber_count_;
};

class CookingYoutubeChannel : public YoutubeChannel {
  public:
    CookingYoutubeChannel(string name, string owner_name)
        : YoutubeChannel(name, owner_name) {}

    void Practice() {
        cout << owner_name_ << " is practicing cooking!" << endl;
    }
};

class SingersYoutubeChannel : public YoutubeChannel {
  public:
    SingersYoutubeChannel(string name, string owner_name)
        : YoutubeChannel(name, owner_name) {}

    void Practice() {
        cout << owner_name_ << " is practicing singing!" << endl;
    }
};

int main() {
    CookingYoutubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
    SingersYoutubeChannel singingYtChannel("John's Songs", "John");

    // Polymorphism works for pointers.
    // The pointer points to the base class.
    YoutubeChannel* pt1 = &cookingYtChannel;
    YoutubeChannel* pt2 = &singingYtChannel;

    pt1->set_subscriber_count(2);
    pt2->set_subscriber_count(20);

    // The same function but active differently.
    pt1->Quality();
    pt2->Quality();

    return 0;
}