// Import Libraries
#include <iostream> // IO Library
#include <fstream>
#include <algorithm>
#include <cmath>


// #include "libraries.h"
// #include "app/framework.cpp"

// Import namespace 'std'
using namespace std;

int a();

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
    int n, m;
    cin >> n >> m;
    int arr[n+1][m+1];

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++)
            cin >> arr[i][j];
    }
    for (int i=2;i<=n;i++) {
        for (int j=1;j<=m;j++){
            if (arr[i-1][j] > arr[i][j]) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}

// Functions Definition


