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
    int arr[101], arrb[101];
    for (int i=1;i<=l;i++) {
        int x;
        cin >> arr[i] >> arrb[i];
    }
    int m=0;

    for (int i=1;i<=l;i++) {
        for (int j=1;j<=l-i;j++)
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                temp = arrb[j];
                arrb[j] = arrb[j+1];
                arrb[j+1] = temp;
            }
    }
    for (int i=1;i<=l;i++) {
        if (arrb[i])
            continue;
        cout << arr[i] << ' ';
    }
    for (int i=1;i<=l;i++) {
        if (!arrb[i])
            continue;
        cout << arr[i] << ' ';
    }

    return 0;
}

// Functions Definition


