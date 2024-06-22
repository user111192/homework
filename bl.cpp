#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <random>
#include <stack>
#include <set>


using namespace std;
const int MAX = 100010;
typedef long long ll;

template<typename Type>
Type mymod(Type a, Type b) {
    if (a>=0) {
        return a%b;
    } else {
        return b-(-a)%b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    ll a, m, l, r, ans = 0;
    cin >> a >> m >> l >> r;
    ll s = mymod(a, m);
    for (ll i=l;i<=r;i++) {
        if (mymod(i, m) == s) {
            ans++;
        }
    }
    cout << ans << endl;


    // 这一段是输出程序运行时间, 提交到oj时要删掉
    // [-提交到oj时删除-
    double t_used = (1.0 * clock()) / CLOCKS_PER_SEC;
    // printf("Time: %lfs %s \n", t_used, (t_used < 1) ? "\33[32mOK\33[0m" : "\33[31mFAIL\33[0m");
    // -]
    return 0;
}
