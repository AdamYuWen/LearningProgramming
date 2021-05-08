#include <iostream>
using std::cout;
using std::endl;

// Abstract class: has at least one pure virtual function.
// It is to make sure that all derived classes have their own virtual functions.

// ----------------------------------------------------------------
// 1. Cannot create instances of abstract classes.
// 2. Can create pointers to abstract classes.
// 3. No implementation in the base class.
// 4. Derived classes must implement their own functions.
// ----------------------------------------------------------------
class Instrument {
  public:
    virtual void MakeSound() = 0;
};

class Accordion : public Instrument {
  public:
    virtual void MakeSound() { cout << "Accordion playing ..." << endl; }
};

class Piano : public Instrument {
  public:
    virtual void MakeSound() { cout << "Piano playing ..." << endl; }
};

int main() {
    Instrument* i_ptr_1 = new Accordion;
    i_ptr_1->MakeSound();

    Instrument* i_ptr_2 = new Piano;
    i_ptr_2->MakeSound();

    // Combine pointers together and call the function in a for loop.
    Instrument* i_ptr_3[2] = {i_ptr_1, i_ptr_2};
    for (int i = 0; i < 2; i++) {
        i_ptr_3[i]->MakeSound();
    }

    return 0;
}