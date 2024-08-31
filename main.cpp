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
const int MAX = 200010;
const long long inf = (1ll << 60);
typedef long long ll;
int n;
int a[MAX+1];
char h[MAX+1];
ll ans=inf;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i] >> h[i];
    }
    for (int i=1;i<=100;i++) {
        for (int j=1;j<=100;j++) {
            ll nans=0;
            int lpos=i, rpos=j;
            for (int k=1;k<=n;k++) {
                if (h[k] == 'L') nans+=abs(lpos-a[k]), lpos=a[k];
                if (h[k] == 'R') nans+=abs(rpos-a[k]), rpos=a[k];
            }
            ans=min(ans, nans);
        }
    }
    cout << ans << endl;


    return 0;
}

