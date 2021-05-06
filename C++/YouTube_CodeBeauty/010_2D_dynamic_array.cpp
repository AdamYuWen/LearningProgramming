#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Enter the number of rows and columns: ";
    int rows, cols;
    cin >> rows >> cols;

    // table is pointer to dynamic array of pointers, so there are two *.
    // Allcolate memory for a dynamic array of pointers, so ther is one *.
    int** table = new int*[rows];
    for (int i = 0; i < rows; i++) {
        // Allcolate memory for each element in table.
        table[i] = new int[cols];
    }

    table[1][2] = 88;

    // * Print the table.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memories.
    for (int i = 0; i < rows; i++) {
        // Deallocate memory for each element in table.
        delete[] table[i];
    }
    // Deallocate memory for the table points to.
    delete[] table;
    // Assign the pointer to NULL.
    table = NULL;

    return 0;
}