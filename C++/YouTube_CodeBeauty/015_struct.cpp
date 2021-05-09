#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

struct SmartPhones {
    string name;
    int storage_space;
    string color;
    float price;
};

void PrintSmartPhones(SmartPhones s) {
    cout << s.name << endl;
    cout << s.storage_space << endl;
    cout << s.color << endl;
    cout << s.price << endl;
}

struct Person {
    string name;
    int age;
    SmartPhones smart_phone;
};

void PrintPerson(Person p) {
    cout << p.name << endl;
    cout << p.age << endl;
    PrintSmartPhones(p.smart_phone); // Use another print function.
}

int main() {
    SmartPhones iphone;
    iphone.name = "iPhone 12";
    iphone.storage_space = 32;
    iphone.color = "black";
    iphone.price = 999.99;

    PrintSmartPhones(iphone);
    cout << endl;

    SmartPhones samsung;
    samsung.name = "Samsung Galaxy S21 Ultra";
    samsung.storage_space = 64;
    samsung.color = "gray";
    samsung.price = 888.88;

    PrintSmartPhones(samsung);
    cout << endl;

    Person person;
    person.name = "Saldina";
    person.age = 26;
    // person.smart_phone = samsung; // It also works.
    person.smart_phone.name = "Samsung Galaxy S21 Ultra";
    person.smart_phone.storage_space = 64;
    person.smart_phone.color = "gray";
    person.smart_phone.price = 888.88;

    PrintPerson(person);

    return 0;
}