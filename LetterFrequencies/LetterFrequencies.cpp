#include <iostream>
#include <fstream>
#include <algorithm>

const int NUM_LETTERS = 26;

// Function to check if a file exists
bool fileExists(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

// Function to count letter frequencies
void countLetterFrequencies(const std::string& filename, int frequencies[]) {
    std::ifstream inputFile(filename);

    char ch;
    while (inputFile >> ch) {
        if (isalpha(ch)) {
            ch = toupper(ch);  // Convert to uppercase
            frequencies[ch - 'A']++;
        }
    }

    inputFile.close();
}

// Function to display letter frequencies in alphabetical order
void displayAlphabeticalOrder(const int frequencies[]) {
    std::cout << "Letter frequencies in alphabetical order:\n";
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        std::cout << letter << ": " << frequencies[letter - 'A'] << '\n';
    }
}

// Function to sort letters by frequency in ascending order
void sortLettersByFrequency(const int frequencies[], char letters[]) {
    for (int i = 0; i < NUM_LETTERS; ++i) {
        letters[i] = static_cast<char>('A' + i);
    }

    std::sort(letters, letters + NUM_LETTERS, [&frequencies](char a, char b) {
        return frequencies[a - 'A'] < frequencies[b - 'A'];
    });
}

// Function to display letter frequencies in ascending order of their frequencies
void displayFrequencyOrder(const int frequencies[], const char letters[]) {
    std::cout << "\nLetter frequencies in ascending order of frequencies:\n";
    for (int i = 0; i < NUM_LETTERS; ++i) {
        std::cout << letters[i] << ": " << frequencies[letters[i] - 'A'] << '\n';
    }
}

int main() {
    std::string filename;

    // Prompt user to provide the name of the text file
    do {
        std::cout << "Enter the name of the text file: ";
        std::cin >> filename;

        if (!fileExists(filename)) {
            std::cout << "File does not exist. Please enter a valid filename.\n";
        }

    } while (!fileExists(filename));

    int frequencies[NUM_LETTERS] = {0};
    countLetterFrequencies(filename, frequencies);

    // Display frequencies in alphabetical order
    displayAlphabeticalOrder(frequencies);

    char letters[NUM_LETTERS];
    sortLettersByFrequency(frequencies, letters);

    // Display frequencies in ascending order of frequencies
    displayFrequencyOrder(frequencies, letters);

    return 0;
}


    