// Import Libraries
#include <iostream> // IO Library


// #include "libraries.h"
// #include "app/framework.cpp"

#define final const

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
    int arr[l+1];
    for (int i=0;i<l+1;i++)
        arr[i] = 0; // (必须)设置初始值
    for (int i=0;i<l;i++)
        cin >> arr[i];

    int count = 1, m = INT32_MIN;
    // 遍历数组
    for (int i=0;i<l;i++) {
        for (int j=i;j<l;j++) {
            int c = 0;
            for (int k = i; k <= j; k++)
                c += arr[k];
            if (c >= m)
                m = c;
        }
    }
    // 输出m
    cout << m;
    return 0;
}

// Functions Definition


