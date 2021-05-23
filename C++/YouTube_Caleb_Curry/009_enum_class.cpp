#include <iostream>
using std::cout;
using std::endl;

int main() {
    // enum class works in C++11
    enum class Season { spring, summer, fall, winter };
    // They only work in Season.
    Season season = Season::winter;
    switch (season) {
    case Season::spring:
        break;
    case Season::summer:
        break;
    case Season::fall:
        break;
    case Season::winter:
        cout << "Stay warm!" << endl;
        break;
    }

    return 0;
}