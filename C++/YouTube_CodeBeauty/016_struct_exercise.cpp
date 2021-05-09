#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct MultipleChoice {
    string question;
    string option_1;
    string option_2;
    string option_3;
    int answer;
};

int main() {
    MultipleChoice q1;
    q1.question = "What is the smallest country?";
    q1.option_1 = "1. USA";
    q1.option_2 = "2. India";
    q1.option_3 = "3. Vatican City";
    q1.answer = 3;

    MultipleChoice q2;
    q2.question = "What's the biggest animal in the world?";
    q2.option_1 = "1. Elephant";
    q2.option_2 = "2. Blue whale";
    q2.option_3 = "3. Great white shark";
    q2.answer = 2;

    MultipleChoice q3;
    q3.question = "How many elements are there in the periodic table";
    q3.option_1 = "1. 118 elements";
    q3.option_2 = "2. 119 elements";
    q3.option_3 = "3. 120 elements";
    q3.answer = 1;

    MultipleChoice* mc_array = new MultipleChoice[3];
    mc_array[0] = q1;
    mc_array[1] = q2;
    mc_array[2] = q3;

    for (int i = 0; i < 3; i++) {
        cout << mc_array[i].question << endl;
        cout << mc_array[i].option_1 << endl;
        cout << mc_array[i].option_2 << endl;
        cout << mc_array[i].option_3 << endl;
        cout << "Choose 1-3: ";
        int user_answer;
        cin >> user_answer;
        if (user_answer == mc_array[i].answer) {
            cout << "Correct!" << endl;
        } else {
            cout << "Incorrect!" << endl;
        }
        cout << endl;
    }

    delete[] mc_array;

    return 0;
}