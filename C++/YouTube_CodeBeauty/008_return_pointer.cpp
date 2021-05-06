#include <iostream>
using std::cout;
using std::endl;

// Return multiple values from a function using pointer.
// Pass the value by address, so it changes the value directly.
void GetMinMax(int numbers[], int size, int* min, int* max) {
    for (int i = 0; i < size; i++) {
        if (numbers[i] < *min) {
            *min = numbers[i];
        }
        if (numbers[i] > *max) {
            *max = numbers[i];
        }
    }
}

int main() {
    int numbers[5] = {5, 4, -2, 29, 6};
    int min = numbers[0];
    int max = numbers[0];
    GetMinMax(numbers, 5, &min, &max);

    cout << "Min = " << min << " Max = " << max << endl;

    return 0;
}