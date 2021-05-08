#include "013_header_function.h"
#include <iostream>
using std::cout;
using std::endl;

// Compliers convert cpp files to object files.
// All cpp files are independent from each other.
// Linkers link all object files together.
// All object files together is the executable file.

// If we want to use a function in different cpp files, we need to have function
// declaration in all the cpp files.
// However, we cannot define a function more than once. Otherwise, the program
// doesn't know which function it should use.

// If only one function is used by multiple cpp files, copying and pasting the
// function declarations here and there seems possible. However, if there are
// 100 functions that want to used in multiple cpp files, it is very hard to
// copy and paste. Then, we want to put them in one header file and include the
// header file here and there, which is only one line of code.

// The header files only include function declarations and their corresponding
// cpp files include function definitions.
int main() {
    cout << "Today I'll eat " << RecommendMeAFood('c') << endl;

    return 0;
}