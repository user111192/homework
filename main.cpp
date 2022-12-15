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
    int arr[101];
    for (int i=0;i<101;i++)
        arr[i]=0;
    for (int i=1;i<=l;i++) {
        int x;
        cin >> x;
        arr[x]++;
    }

    for (int i=100;i>=1;i--)
        for (int j=1;j<=arr[i];j++)
            cout << i << " ";
    return 0;
}

// Functions Definition


