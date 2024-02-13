#include <iostream>
#include<conio.h>

void printDiamond(int n) {
    // Print upper part of the diamond
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j)
            std::cout << " ";
        for (int k = 0; k < 2 * i + 1; ++k)
            std::cout << "*";
        std::cout << std::endl;
    }

    // Print lower part of the diamond
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j)
            std::cout << " ";
        for (int k = 0; k < 2 * i + 1; ++k)
            std::cout << "*";
        std::cout << std::endl;
    }
}

int main() {
    int n;

    // Get user input for n
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Validate input
    if (n < 0) {
        std::cerr << "Error: Please enter a non-negative integer for n." << std::endl;
        return 1;
    }

    // Print diamond pattern
    printDiamond(n);

    // Wait to display diamond
    getch();

    return 0;
}