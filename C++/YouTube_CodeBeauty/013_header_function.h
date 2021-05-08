// ! Do NOT include a header file more than once in a specific cpp file.

// * "#pragma once" works the same as
// #ifndef FILE_
// #define FILE_
// #endif // FILE_

// In Google C++ Style Guide, it says that don't use the following line of code.
#pragma once

// A function declaration tells the compiler about a function's name, return
// type, and parameters. A function definition provides the actual body of the
// function.

const char* RecommendMeAFood(char firstLetter);