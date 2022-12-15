// Import Libraries
#include <iostream> // IO Library
#include <fstream>
#include <algorithm>
#include <cmath>


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
    for (int i=0;i<l;i++) {
        int MaxPoint = i;
        for (int j=i;j<l;j++) {
            if (arr[j] > arr[MaxPoint])
                MaxPoint = j;
        }
        // Swap
        int temp;
        temp = arr[i];
        arr[i] = arr[MaxPoint];
        arr[MaxPoint] = temp;
    }
    for (int i=0;i<l;i++)
        cout << arr[i] << ' ';
    return 0;
}

// Functions Definition


