#include <iostream>
using std::cout;
using std::endl;

// 006_polymorphism.cpp: The function is in the base class. Derived classes can
// use the function. Then, derived classes can use the function as their own.
//
// 011_virtual_function.cpp: The functions are in both base class and derived
// classes. Derived classes use their own functions.

class Instrument {
  public:
    virtual void MakeSound() { cout << "Instrument playing ..." << endl; }
};

class Accordion : public Instrument {
  public:
    virtual void MakeSound() { cout << "Accordion playing ..." << endl; }
};

int main() {
    // The following two methods are the same.
    // ! If there is no "virtual", it calls the the function in base class.
    // 1. If the function is virtual in the base class and derived classes have
    // the same function, the derived classes use their own functions (it
    // doesn't matter which class the pointers point to (base or derived)).
    // 2. If the function is NOT virtual in the base class, derived classes can
    // either use the function in base class or the function in derived classes.
    // It depends on which class the pointers point to.
    Instrument* i_ptr_1 = new Accordion;
    i_ptr_1->MakeSound();

    Accordion acc;
    Instrument* i_ptr_2 = &acc;
    i_ptr_2->MakeSound();

    return 0;
}