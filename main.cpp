#include <bits/stdc++.h>
//       ^^^^^^^^^^^^^^^
// 你看头文件也是老师的写法.

using namespace std;
const int MAX = 110;
const int P = 1000000007;


// 声 明
// 我的代码完全按照老师的做法来写, 没有使用其他方法。



int main() {


    // 这一段是输出程序运行时间, 提交到oj时要删掉
    // [-提交到oj时删除-
    double t_used = (1.0 * clock()) / CLOCKS_PER_SEC;
    //printf("Time: %lfs %s \n", t_used, (t_used < 1) ? "\33[32mOK\33[0m" : "\33[31mFAIL\33[0m");
    //print_memo_use();
    // -]
    return 0;
}

void print_memo_use() {
    double mem_used;
    FILE *ff = nullptr;
    int pid = 0;

    system("pgrep homework > xxs");
    ff = fopen("xxs", "r");
    fscanf(ff, "%d", &pid);
    char pidc[101]{};
    sprintf(pidc, "top -pid %d -l 1 | tail -n 1 | awk '{print $8}' > xt", pid);
    system(pidc);
    ff = fopen("xt", "r");
    fscanf(ff, "%lf", &mem_used);
    mem_used /= 1000.0;
    printf("Memory: %lfMB %s\n", mem_used, (mem_used < 128) ? "\33[32mOK\33[0m" : "\33[31mFAIL\33[0m");
}
