#include "013_header_function.h"

// ! Can ONLY define a function once!
// "const char*" is a way to return strings.
const char* RecommendMeAFood(char firstLetter) {
    if (firstLetter == 'a' || firstLetter == 'A')
        return "apple";
    else if (firstLetter == 'b' || firstLetter == 'B')
        return "banana";
    else if (firstLetter == 'c' || firstLetter == 'C')
        return "chocolate";
    else
        return "pizza";
}