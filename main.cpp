#include <bits/stdc++.h>
//       ^^^^^^^^^^^^^^^
// 你看头文件也是老师的写法.

using namespace std;
const int MAX = 1005;
typedef long long ll;
const ll inf = 1ll << 60;
#define qq(x) (weixin(x))
#define weixin(x) (alipay(x))
#define alipay(x) (pdd(x))
#define pdd(x) ((x))
int dp[MAX+1][MAX+1], n, m, v[MAX+1],w[MAX+1], ans;


int main() {
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",v+i,w+i);
    }
    // 转移 dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
    memset(dp,128,sizeof(dp));
    dp[0][0] = 0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (j < v[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
        }
    }
    for (int i=0;i<=m;i++)
        ans = max(ans,dp[n][i]);

    printf("%d\n",ans);

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
    sprintf(pidc, "top -pid %d -l 1 | tail -n 1 | awk '{prll $8}' > xt", pid);
    system(pidc);
    ff = fopen("xt", "r");
    fscanf(ff, "%lf", &mem_used);
    mem_used /= 1000.0;
    printf("Memory: %lfMB %s\n", mem_used, (mem_used < 128) ? "\33[32mOK\33[0m" : "\33[31mFAIL\33[0m");
}
