#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/**
 * public - members are accessible from outside the class
 * private - members cannot be accessed (or viewed) from outside the class
 * protected - members cannot be accessed from outside the class, however, they
 *             can be accessed in inherited classes.
 *
 * https://www.programiz.com/cpp-programming/public-protected-private-inheritance
 * * By default, it is private
 * public inheritance makes public members of the base class public in the
 * derived class, and the protected members of the base class remain protected
 * in the derived class.
 * protected inheritance makes the public and protected members of the base
 * class protected in the derived class.
 * private inheritance makes the public and protected members of the base class
 * private in the derived class. (So, outside of the derived class cannot access
 * the members, which mean it cannot be used in the main function.)
 */

/**
 * * Key Points:
 * 1. pure virtual function requires derived classes to implement the functions
 * 2. access specific: public, protected, private
 * 3. inheritance: public, protected, private
 * 4. polymorphism: if we use pointers and they points to the base class, key
 * word "virtual" must be used
 */

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : public AbstractEmployee {
  public:
    Employee(string name, string company, int age) {
        name_ = name;
        company_ = company;
        age_ = age;
    }

    string get_name() { return name_; }
    void set_name(string name) { name_ = name; }

    void Intro() {
        cout << "Name - " << name_ << endl;
        cout << "Company - " << company_ << endl;
        cout << "Age - " << age_ << endl;
    }

    void Work() { cout << "Employee Class " << endl; }

    virtual void VirtualWork() { cout << "Employee Class " << endl; }

    // Derived classes must implement the pure virtual function.
    virtual void AskForPromotion() {
        if (age_ > 30)
            cout << name_ << " got promoted!" << endl;
        else
            cout << name_ << ", sorry NO promotion for you!" << endl;
    }

  protected:
    int age_;

  private:
    string name_;
    string company_;
};

class Developer : public Employee {
  public:
    // Because the base class have constructor, the derived class must have
    // constructor as well.
    Developer(string name, string company, int age, string fav_program_language)
        : Employee(name, company, age) { // Use Employee's constructor.
        fav_program_language_ = fav_program_language;
    }

    void Intro() {
        // ! The following 3 lines do NOT work, because it has NO access to base
        // ! private members (public inheritance)
        // cout << "Name - " << name_ << endl;
        // cout << "Company - " << company_ << endl;
        // cout << "Age - " << age_ << endl;

        // ! If we want to access them, we can have get functions or change the
        // ! variables from private to protected in base class. Or, use public
        // ! functions in base class.
        cout << get_name() << " is " << age_ << " years old." << endl;
        Employee::Intro();
        cout << "Favourite Programming Language - " << fav_program_language_
             << endl;
    }

    void Work() { cout << "Developer Class " << endl; }

    virtual void VirtualWork() { cout << "Developer Class " << endl; }

  private:
    string fav_program_language_;
};

class Teacher : public Employee {
  public:
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age) {
        subject_ = subject;
    }

    void PrepareLession() {
        cout << get_name() << "is prepreing " << subject_ << " lesson." << endl;
    }

    void Work() { cout << "Teacher Class " << endl; }

    virtual void VirtualWork() { cout << "Teacher Class " << endl; }

  private:
    string subject_;
};

int main() {
    Employee e1 = Employee("Saldina", "YT-CodeBeauty", 25);
    Employee e2 = Employee("John", "Amazon", 35);

    e1.Intro();
    cout << endl;
    e2.Intro();

    e1.AskForPromotion();
    e2.AskForPromotion();
    cout << endl;

    // ****************************************************************
    Developer d = Developer("Saldina", "YT-CodeBeauty", 25, "C++");
    d.Intro();

    // If it is "class Developer : private Employee" (private instead of
    // public), the following function cannot be used, because of private
    // inheritance.
    d.AskForPromotion();
    cout << endl;

    // ****************************************************************
    Teacher t = Teacher("Jack", "Cool School", 35, "History");
    t.PrepareLession();
    t.AskForPromotion();
    cout << endl;

    // ****************************************************************
    d.Work(); // If we directly call the function, don't need to have "virtual"
    t.Work();
    cout << endl;

    // ****************************************************************
    // Without key word "virtual", it only uses Employee::Work().
    Employee* e1_ptr = &d;
    Employee* e2_ptr = &t;
    e1_ptr->Work();
    e2_ptr->Work();
    cout << endl;

    // ****************************************************************
    // With key word "virtual", it calls Developer::Work() and Teacher::Work().
    // If the pointer can points to the base class, it may save lots of space.
    e1_ptr = &d;
    e2_ptr = &t;
    e1_ptr->VirtualWork();
    e2_ptr->VirtualWork();
    cout << endl;

    return 0;
}