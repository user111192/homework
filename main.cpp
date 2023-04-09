#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int MAX = 10002;

void print_memo_use();

int n, c[11];

inline void dfs(int i) {
    // printf("%d->",i);
    if (i == n + 1) {
        for (int j = 1; j <= n; j++)
            printf("%d", c[j]);

        printf("\n");
        return;
    }
    c[i] = 0;
    dfs(i + 1);
    c[i] = 1;
    dfs(i + 1);
}

int main() {
    scanf("%d", &n);
    dfs(1);
    // ans = k[n];
    // cout << ans;
    // 这一段是输出程序运行时间, 提交到oj时要删掉
    // [-提交到oj时删除-
    double t_used = (1.0 * clock()) / CLOCKS_PER_SEC;
    printf("Time: %lfs %s \n", t_used, (t_used < 1) ? "\33[32mOK\33[0m" : "\33[31mFAIL\33[0m");
    print_memo_use();
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