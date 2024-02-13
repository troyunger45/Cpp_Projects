# Letter Frequencies ReadMe

This C++ program reads text from a user-specified file, counts the frequencies of English letters case-insensitive, and displays the results. It uses arrays to store letter frequencies and performs sorting for better readability.

## Features
- **File Existence Check:** Ensures that the specified text file exists before processing.
- **Letter Frequency Counting:** Counts the frequencies of English letters ignoring non-alphabetic characters.
- **Display in Alphabetical Order:** Shows letter frequencies in alphabetical order.
- **Display in Frequency Order:** Displays letter frequencies in ascending order of their occurrences.

## Usage
1. Run the program.
2. Enter the name of the text file when prompted.
3. View the letter frequencies in alphabetical order.
4. View the letter frequencies in ascending order of occurrences.

## Compilation
```bash
g++ LetterFrequencies.cpp -o LetterFrequencies
```
## Execution

```bash
./LetterFrequencies
```

## Example
*Not the real output of the program.*
```plain text
Enter the name of the text file: input.txt
Letter frequencies in alphabetical order:
A: 10
B: 5
...
Z: 3
```

``` plain text
Letter frequencies in ascending order of frequencies:
Z: 3 
B: 5
...
A: 10
```

## Program Logic

*The program follows these steps:*

1. **User Input:** The main function prompts the user to enter the name of a text file.

    ```c++
    do {
        std::cout << "Enter the name of the text file: ";
        std::cin >> filename;

        if (!fileExists(filename)) {
            std::cout << "File does not exist. Please enter a valid filename.\n";
        }

    } while (!fileExists(filename));
    ```

    The program ensures the entered file exists, repeatedly prompting the user until a valid filename is provided.

2. **Count Letter Frequencies:** The `countLetterFrequencies` function reads characters from the file, counting the frequencies of English letters ignoring case and updating the `frequencies` array.

    ```c++
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

    int main(){
        // Rest of code
        int frequencies[NUM_LETTERS] = {0};
        countLetterFrequencies(filename, frequencies);
        // Rest of code
    }
    ```

3. **Display in Alphabetical Order:** The program displays letter frequencies in alphabetical order.

    ```c++
    // Function to display letter frequencies in alphabetical order
    void displayAlphabeticalOrder(const int frequencies[]) {
        std::cout << "Letter frequencies in alphabetical order:\n";
        for (char letter = 'A'; letter <= 'Z'; ++letter) {
            std::cout << letter << ": " << frequencies[letter - 'A'] << '\n';
        }
    }

    int main(){
        // Rest of code
        int frequencies[NUM_LETTERS] = {0};
        countLetterFrequencies(filename, frequencies);
        // Display frequencies in alphabetical order
        displayAlphabeticalOrder(frequencies);
        // Rest of code
    }
    
    ```

4. **Sort Letters by Frequency:** The `sortLettersByFrequency` function sorts the letters based on their frequencies.
    
    ```c++
    // Function to sort letters by frequency in ascending order
    void sortLettersByFrequency(const int frequencies[], char letters[]) {
        for (int i = 0; i < NUM_LETTERS; ++i) {
            letters[i] = static_cast<char>('A' + i);
        }

        std::sort(letters, letters + NUM_LETTERS, [&frequencies](char a, char b) {
            return frequencies[a - 'A'] < frequencies[b - 'A'];
        });
    }

    int main(){
        // Rest of code
        int frequencies[NUM_LETTERS] = {0};
        countLetterFrequencies(filename, frequencies);
        // Rest of code
        char letters[NUM_LETTERS];
        sortLettersByFrequency(frequencies, letters);
        // Rest of code
    }
    ```

5. **Display in Frequency Order:** The program displays letter frequencies in ascending order of their frequencies.

    ```c++
    // Function to display letter frequencies in ascending order of their frequencies
    void displayFrequencyOrder(const int frequencies[], const char letters[]) {
        std::cout << "\nLetter frequencies in ascending order of frequencies:\n";
        for (int i = 0; i < NUM_LETTERS; ++i) {
            std::cout << letters[i] << ": " << frequencies[letters[i] - 'A'] << '\n';
        }
    }

    int main(){
        // Rest of code
        int frequencies[NUM_LETTERS] = {0};
        countLetterFrequencies(filename, frequencies);
        // Rest of code
        char letters[NUM_LETTERS];
        sortLettersByFrequency(frequencies, letters);
        displayFrequencyOrder(frequencies, letters);
        // Rest of code
    }
    
    ```
## Note
- Ensure the input text file is in the same directory as the program.
- The program ignores non-alphabetic characters in the text file.
- In case of issues, the program prompts for a valid filename.