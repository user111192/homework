// Import Libraries
#include <iostream> // IO Library
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

// #include "libraries.h"
// #include "app/framework.cpp"

// Import namespace 'std'
using namespace std;

bool DEBUG_MODE = true;

/*
     * MM      MM     AA     DDDDDDDD EEEEEEEE
     * M M    M M    A  A    D     D  E
     * M  M  M  M   AAAAAA   D     D  EEEEEEEE
     * M   MM   M  A      A  D     D  E
     * M   MM   M AAAAAAAAAA DDDDDDDD EEEEEEEE
     */

// Main Function
int main(int argc, char **argv) {
    /**
     * @param argc int
     * Argument Numbers
     * @param argv char[][]
     * 2-D Array (char)
     * @return Exit code
     */
    //

    if (argc == 2) {
        if (!strcmp(argv[1], "--debug") || !strcmp(argv[1], "--debug:on"))
            DEBUG_MODE = true;
        else if (!strcmp(argv[1], "--no-debug") || !strcmp(argv[1], "--debug:off"))
            DEBUG_MODE = false;
    }
    char s[1001];
    int a[1001], b, c[2002];
    b=0;
    for (int i = 0; i < 1001; i++) {
        s[i] = '0';
        a[i] = 0, c[i] = 0;
    }
    scanf("%s", s + 1);
    int lena = strlen(s + 1); // NOLINT(cppcoreguidelines-narrowing-conversions)

    for (int i = 1; i <= lena + 1; i++)
        a[i] = s[lena - i + 1] - '0';

    scanf("%d", &b);
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    int lenc = lena;
    int r=0;

    for (int i=lena;i>0;--i) {
        r = r*10 + a[i];
        c[i] = r/b;
        r %= b;
    }

    // 移除多余0
    while (c[lenc] == 0 && lenc > 1) {
        --lenc;
    }


    // Output

    for (int i = lenc; i >= 1; i--)
        printf("%d", c[i]);
    printf("\n%d",r);
    return 0;
}


// Functions Definition


