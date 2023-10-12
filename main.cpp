#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAX = 3010;
typedef long long ll;
int n, m, cnt;
int edges[MAX+1][MAX+1];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1,u,v;i<=m;i++) {
        cin >> u >> v;
        edges[u][v] = 1;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (!edges[i][j]) continue;
            if (i==j) continue;
            for (int k=1;k<=n;k++) {
                if (!edges[j][k]) continue;
                if (i==k || j==k) continue;
                for (int l=1;l<=n;l++) {
                    if (!edges[i][l]) continue;
                    if (!edges[l][k]) continue;
                    if (i==l || j==l || k==l) continue;
                    if (i!=j && j!=k && k!=l && i!=k && j!=l && i!=l) {
                        // a->b,b->c,a->d,d->c
                        if (edges[i][j] && edges[j][k] && edges[i][l] && edges[l][k]) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt/2 << endl;
    

    // 这一段是输出程序运行时间, 提交到oj时要删掉
    // [-提交到oj时删除-
    double t_used = (1.0 * clock()) / CLOCKS_PER_SEC;
    // printf("Time: %lfs %s \n", t_used, (t_used < 1) ? "\33[32mOK\33[0m" : "\33[31mFAIL\33[0m");
    // -]
    return 0;
}