# 背包问题转移式+核心代码

```c++
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000; // data range
const int P = 1000000007;

int n, m, v[MAX+1], w[MAX+1], t[MAX+1];

int main() {
    
    for (int j=m;j>=v[i];j--) {
```

## 一、`01`背包
// 01背包
// 转移 dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
## 二、`完全`背包
// 完全背包
// for (int j=v[i];j<=m;j++)
// 转移 dp[j] = max(dp[j],dp[j-v[i]]+w[i]);

## 三、`多重`背包
// 多重背包
// for (int k=1;k<=l[i];k++)
//     for (int j=m;j>=v[i];--j)
// 转移 dp[j] = max(dp[j], dp[j-v[i]]+w[i]);

## ⭐️四、`混合`背包
分别处理即可。(代码**略**)

```c++
    }
    return 0; 
}
```