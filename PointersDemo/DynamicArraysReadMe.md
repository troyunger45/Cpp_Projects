# C++ Dynamic Arrays ReadMe

## Functions

**duplicate:**

Takes a pointer to a dynamic array of integers and its size.
Returns a new dynamic array containing two copies of each element.

```
// Function to duplicate the content of a dynamic array
int* duplicate(const int* arr, int size) {
    int* duplicatedArr = new int[2 * size];

    for (int i = 0; i < size; ++i) {
        duplicatedArr[i] = arr[i];
        duplicatedArr[i + size] = arr[i];
    }

    return duplicatedArr;
}
```

**generate:**

Takes an unsigned integer n.
Creates a dynamic array of n random integers using rand.
Returns a pointer to the generated dynamic array.

```
// Function to generate a dynamic array of random integers
int* generate(unsigned int n) {
    int* randomArr = new int[n];

    for (unsigned int i = 0; i < n; ++i) {
        randomArr[i] = rand();  // Using rand() to generate random integers
    }

    return randomArr;
}
```

**display:**

Takes a pointer to a dynamic array of integers and its size.
Displays the content with 8 integers per line, except for the last line.

```
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
```

## Compilation:

```
g++ DynamicArrays.cpp -o DynamicArrays
```

## Execution:

```
./DynamicArrays
```

## Example

```
Original Array: 1 2 3 4 5

Duplicated Array: 1 2 3 4 5 1 2 3
4 5

Generated Random Array: 14961 28169 8363 15223 16941 6957 12662 4272
15087 6615
```

## Usage:

- main function demonstrates the functions.
- duplicate duplicates an array; both arrays are displayed.
- generate creates a dynamic array of random integers, displayed.
- display formats output, showing 8 integers per line.

## Note:

Ensure to use delete[] for proper memory management, preventing memory leaks.




