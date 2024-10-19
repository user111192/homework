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
#include <list>
#include <thread>


using namespace std;
const int MAX = 500010;
const long long inf = (1ll << 60);
typedef long long ll;
int T, n;


int main() {
    // ios::sync_with_stdio(false);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int h1, m1, h2, m2;
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            int t1 = h1 * 60 + m1;
            int t2 = h2 * 60 + m2;
            if (t2 < t1) t2 += 24 * 60;
            ans += max(ans, t2 - t1);
        }
        printf("%d\n", ans);
    }



    return 0;
}