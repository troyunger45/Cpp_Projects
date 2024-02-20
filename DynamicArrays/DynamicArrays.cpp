#include <iostream>
#include <cstdlib>  // For rand function
#include <ctime>    // For srand function

using namespace std;

// Function to duplicate the content of a dynamic array
int* duplicate(const int* arr, int size) {
    int* duplicatedArr = new int[2 * size];

    for (int i = 0; i < size; ++i) {
        duplicatedArr[i] = arr[i];
        duplicatedArr[i + size] = arr[i];
    }

    return duplicatedArr;
}

// Function to generate a dynamic array of random integers
int* generate(unsigned int n) {
    int* randomArr = new int[n];

    for (unsigned int i = 0; i < n; ++i) {
        randomArr[i] = rand();  // Using rand() to generate random integers
    }

    return randomArr;
}

// Function to display the content of a dynamic array
void display(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";

        // Display 8 integers per line
        if ((i + 1) % 8 == 0) {
            cout << endl;
        }
    }

    // Display the remaining integers on the last line
    if (size % 8 != 0) {
        cout << endl;
    }
}

int main() {
    // Random number generator
    srand(time(0));

    // Demonstrate duplicate function
    int originalArr[] = {1, 2, 3, 4, 5};
    int originalSize = sizeof(originalArr) / sizeof(originalArr[0]);

    int* duplicatedArr = duplicate(originalArr, originalSize);

    cout << "Original Array: ";
    display(originalArr, originalSize);

    cout << "\nDuplicated Array: ";
    display(duplicatedArr, 2 * originalSize);

    delete[] duplicatedArr;  // Free memory

    // Demonstrate generate function
    unsigned int n = 10;
    int* randomArr = generate(n);

    cout << "\nGenerated Random Array: ";
    display(randomArr, n);

    delete[] randomArr;  // Free memory

    return 0;
}
