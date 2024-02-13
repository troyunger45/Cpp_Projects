# DiamondPattern ReadMe

This C++ program generates a diamond pattern based on user input. The diamond consists of asterisks (*) and spaces, creating a visually appealing shape.

## Compilation Command

To compile the program, you can use a C++ compiler such as g++. Open your terminal or command prompt and navigate to the directory containing the source code file DiamondPattern.cpp. Then, use the following command:

```bash
g++ DiamondPattern.cpp -o DiamondPattern
```

## Usage Instructions

1. Compile the program using the provided compilation command.

2. Run the executable DiamondPattern.

3. Enter a non-negative integer for n when prompted.

4. Observe the generated diamond pattern.

## Program Logic

*The program follows these steps:*

1. **User Input:** The main function prompts the user to enter a value for n.

    ```c++
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    ```

2. **Input Validation:** The program checks if the entered value is non-negative. If not, it displays an error message and exits.

    ```c++
    if (n < 0) {
        std::cerr << "Error: Please enter a non-negative integer for n." << std::endl;
        return 1;
    }
    ```
3. **Printing Diamond:** The printDiamond function is responsible for printing the upper and lower parts of the diamond. Here's how it works:

    ```c++
    void printDiamond(int n){
    // Code to print diamond.
    }
    ```
    1. **Upper Part:** For each row, the program calculates the number of spaces and asterisks needed. It uses nested loops to control the placement of these characters, resulting in the upper part of the diamond.

        ```c++
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < n - i; ++j)
                std::cout << " ";
            for (int k = 0; k < 2 * i + 1; ++k)
                std::cout << "*";
            std::cout << std::endl;
        }
        ```

    2. **Lower Part:** Similar to the upper part, the program prints the lower part of the diamond using nested loops. It reverses the process, gradually decreasing the number of asterisks in each row.
    
        ```c++
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n - i; ++j)
                std::cout << " ";
            for (int k = 0; k < 2 * i + 1; ++k)
                std::cout << "*";
            std::cout << std::endl;
        }
        ```

4. **Display:** After printing the diamond pattern, the program uses the getch function to wait for a key press before exiting. This ensures that the user has time to view the diamond pattern before the console window closes.

    ```c++
    printDiamond(n);
    getch();
    ```

## Displayed Diamond Patterns:

*Run with n = 3:*

```bash
./DiamondPattern
```

**Output:**
```
  *
 ***
*****
 ***
  *
```

*Run with n = 5:*

```bash
./DiamondPattern
```

**Output:**
```
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```