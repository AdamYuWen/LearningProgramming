#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class User {
  public:
    User() {
        _first_name = "";
        _last_name = "";
        count++;
    }

    User(string first_name, string last_name) {
        // Sometimes, people use this
        this->_first_name = first_name;
        this->_last_name = last_name;
        count++;
    }

    ~User() { count--; }

    // Key word "static" is not required, but good to have.
    static int get_count() { return count; }

    // operator overloading +
    User operator+(const User& other) {
        User res;
        res._first_name = _first_name + "+" + other._first_name;
        res._last_name = _last_name + "+" + other._last_name;
        return res;
    }

    // operator overloading >> and <<
    // * Functions can access private members by using "friend".
    friend std::istream& operator>>(std::istream& is, User& user);
    friend std::ostream& operator<<(std::ostream& os, const User& user);

  private:
    string _first_name;
    string _last_name;

    // ! Cannot "static int count = 0;"
    // non-const static data member must be initialized out of line.
    static int count; // not associated with objects, associated with class
};

// Do not assign memory when we create each object.
int User::count = 0;

// user must pass by reference, otherwise the values cannot be assigned.
// Because we are going to assign user, it cannot be const.
std::istream& operator>>(std::istream& is, User& user) {
    is >> user._first_name >> user._last_name;
    return is;
}

// Because cout is an object of ostream, the return type is ostream.
// Because we don't want to make copies, use pass by reference (&).
// After os, we want to append more staff, then return os.
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user._first_name << ", " << user._last_name;
    return os;
}

int main() {
    User user_1("Caleb", "Curry");
    User user_2;
    cout << "Enter your first name and last name: ";
    cin >> user_2;

    cout << user_1.get_count() << endl;
    cout << user_1 << endl;
    cout << user_1 + user_2 << endl;

    return 0;
}