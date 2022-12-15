// Import Libraries
#include <iostream> // IO Library
#include <fstream>
#include <algorithm>


// #include "libraries.h"
// #include "app/framework.cpp"

// Import namespace 'std'
using namespace std;

// Main Function
int main(int argc, char **argv) {
    /**
     * @param argc int
     * Argument Numbers
     * @param argv char[][]
     * A 2D Array (char)
     * @return Exit code
     */
    // 读入数组
    int l;
    cin >> l;
    int arr[l];
    for (int i=0;i<l;i++)
        cin >> arr[i];
    for (int i=0;i<l-1;i++) {
        int MinPoint = i;
        for (int j=i;j<l;j++) {
            if (arr[j] < arr[MinPoint])
                MinPoint = j;
        }
        // Swap
        int temp;
        temp = arr[i];
        arr[i] = arr[MinPoint];
        arr[MinPoint] = temp;
    }
    for (int i=0;i<l;i++)
        cout << arr[i] << " ";
    return 0;
}

// Functions Definition


