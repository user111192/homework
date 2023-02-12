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

bool DEBUG_MODE = true;

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
    int a[1001], b[1001], c[1002];
    for (int i = 0; i < 1001; i++) {
        s[i] = '0';
        a[i] = 0, b[i] = 0, c[i] = 0;
    }
    scanf("%s", s + 1);
    int lena = strlen(s + 1);

    for (int i = 1; i <= lena + 1; i++)
        a[i] = s[lena - i + 1] - '0';

    scanf("%s", s + 1);
    int lenb = strlen(s + 1);

    for (int i = 1; i <= lenb + 1; i++)
        b[i] = s[lenb - i + 1] - '0';


    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    int lenc = lena;

    for (int i = 1; i <= 1001; i++)
        c[i] = 0;
    for (int i = 1; i <= lenc; i++) {
        if (DEBUG_MODE) {
            int t = a[i] - b[i] + c[i];
            if (b[i] == 0 && c[i] == 0)
                printf("%d) %d ----------> %d (%c)\n", i, a[i], a[i] - b[i] + c[i],
                       (t == 0 ? '0' : (t >= 0) ? 'P' : 'N'));
            else if (c[i] == 0)
                printf("%d) %d - %d      = %d (%c)\n", i, a[i], b[i], a[i] - b[i] + c[i],
                       (t == 0 ? '0' : (t >= 0) ? 'P' : 'N'));
            else
                printf("%d) %d - %d + %d = %d (%c)\n", i, a[i], b[i], c[i], a[i] - b[i] + c[i],
                       (t == 0 ? '0' : (t >= 0) ? 'P' : 'N'));
        }
        c[i] = a[i] - b[i] + c[i];
        // If c[i] < 0, then c[i] is negative.
        if (c[i] < 0) {
            if (DEBUG_MODE) {
                printf("If c[i(=%d)](=%d) < 0, then %d is negative. \n", i, c[i], c[i]);
                printf("then --c[i+1(=%d)]. c[%d] now is %d (raw: %d). \n", i + 1, i + 1, c[i + 1] - 1, c[i + 1]);
                printf("then c[i(=%d)] += 10. (%d -> %d now)\n", i, c[i], c[i] + 10);
            }
            --c[i + 1];
            c[i] += 10;
        }
    }
    // 处理位数溢出
    while (c[lenc] == 0 && lenc > 1)
        --lenc;

    for (int i = lenc; i >= 1; i--) {
        printf("%d", c[i]);
    }
    return 0;


}


// Functions Definition


