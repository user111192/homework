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
     * MMMMMMMMMM    AA    DDDDDDDD EEEEEEEE
     * M M    M M   A  A   D     D  E
     * M  M  M  M  AAAAAA  D     D  EEEEEEEE
     * M   MM   M A      A D     D  E
     * M   MM   M AAAAAAAA DDDDDDDD EEEEEEEE
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
    int a[1001], b[1001], c[2002];
    for (int i = 0; i < 1001; i++) {
        s[i] = '0';
        a[i] = 0, b[i] = 0, c[i] = 0;
    }
    scanf("%s", s + 1);
    int lena = strlen(s + 1); // NOLINT(cppcoreguidelines-narrowing-conversions)

    for (int i = 1; i <= lena + 1; i++)
        a[i] = s[lena - i + 1] - '0';

    scanf("%s", s + 1);
    int lenb = strlen(s + 1);

    for (int i = 1; i <= lenb + 1; i++)
        b[i] = s[lenb - i + 1] - '0';

    for (int i=1;i<=2001;i++)
        c[i] = 0;

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    int lenc = lena+lenb;

    // 双重循环 时间复杂度: O(n^2)
    for (int i=1;i<=lena;i++) {
        for (int j=1;j<=lenb;j++)
            c[i+j-1] = c[i+j-1] + a[i] * b[j];
        // 得用[i+j-1]而不是[i+j] (因为1base+1base=2base, 得-1)
    }
    bool fl = true;
    for (int i = lenc; DEBUG_MODE && i >= 1; i--) {
        if (c[i] == 0 && fl) {
            continue;
        } else fl = false;
        printf("%d-", c[i]);
    }
    if (DEBUG_MODE)
    printf("\b\n");

    // 进位
    for (int i=1;i<=lenc;i++) {
        c[i+1] = c[i+1] + c[i] /10;
        c[i] %= 10;
    }
    bool first = true;
    // 移除多余0
    while (c[lenc] == 0 && lenc > 1) {
        if (DEBUG_MODE) {
            if (first)
                printf("监测到结果最高位有多余0, 正在清理... ");
            else
                printf("|--------------------------------");
            printf("还剩余%d位\n",lenc-1);
            first = false;
        }
        --lenc;
    }


    // Output

    for (int i = lenc; i >= 1; i--)
        printf("%d", c[i]);
    
    return 0;
}


// Functions Definition


