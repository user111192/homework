// Import Libraries
#include <iostream> // IO Library
#include <cstdio>
#include <cstring>
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
     * 2-D Array (char)
     * @return Exit code
     */
    char s[1001];
    int a[1001], b,c[1002];
    b=0;
    for (int i=0;i<1001;i++) {
        s[i]='0';
        a[i]=0, c[i]=0;
    }
    scanf("%s",s+1);
    int lena = strlen(s+1);

    for (int i=1;i<=lena+1;i++)
        a[i] = s[lena-i+1] - '0';

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    scanf("%d",&b);

    int lenc = lena;

    for (int i=1;i<=1001;i++)
        c[i] = 0;
    for (int i=1;i<=lenc;i++) {
        if (i==1)
            c[i] = a[i] -b;
        else
            c[i] = a[i] + c[i];
        // If c[i] < 0, then c[i] is negative.
        if (c[i] < 0) {
            --c[i+1];
            c[i] += 10;
        }
    }
    // 处理位数溢出
    if (c[lenc]==0 && lenc > 1)
        --lenc;
    for (int i=lenc;i>=1;i--)
        printf("%d", c[i]);
    return 0;
}


// Functions Definition


