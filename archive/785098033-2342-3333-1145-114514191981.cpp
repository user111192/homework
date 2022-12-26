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


void jntm() {}

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
    int a[1001], b[1001],c[1002];
    for (int i=0;i<1001;i++) {
        s[i]='0';
        a[i]=0, b[i]=0, c[i]=0;
    }
    scanf("%s",s+1);
    int lena = strlen(s+1);

    for (int i=1;i<=lena+1;i++)
        a[i] = s[lena-i+1] - '0';

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    scanf("%s",s+1);
    int lenb = strlen(s+1);
    for (int i=1;i<=lenb+1;i++)
        b[i] = s[lenb-i+1] - '0';

    int lenc = (lena>lenb)?lena:lenb;

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    for (int i=1;i<=101;i++)
        c[i] = 0;
    for (int i=1;i<=lenc;i++) {
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ;                                                                                                              ;
        // c[i] = a[i] + b[i]; <-- Wrong
        c[i] = a[i] + b[i] + c[i]; // <-- Correct
        // c[i] += a[i] + b[i]; <-- Plan B, Correct too
        ;                                                                                                              ;
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        // 处理进位
        c[i+1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    // 处理位数溢出
    if (c[lenc+1]>0)
        lenc++;
    for (int i=lenc;i>=1;i--)
        printf("%d", c[i]);
    return 0;
}


// Functions Definition


