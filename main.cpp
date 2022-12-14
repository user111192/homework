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
    int mx = 0;
    bool flag = false;
    for (int i=0;i<l;i++) {
        if ((!flag) && arr[i] == *max_element(arr, arr+l)) {
            flag = true;
            continue;
        }
        if (arr[i] > mx)
            mx = arr[i];
    }
    cout << mx << " ";
    flag = false;
    int ms = INT32_MAX;
    for (int i=0;i<l;i++) {
        if ((!flag) && arr[i] == *min_element(arr, arr+l)) {
            flag = true;
            continue;
        }
        if (arr[i] < ms)
            ms = arr[i];
    }
    cout << ms;
    return 0;
}

// Functions Definition


