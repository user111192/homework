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
int a[MAX+1], f[MAX+1], s[MAX+1], ans=0;


int main() {
    int n;
    cin >> n;
    for (int i=1;i<=2*n;i++) {
        cin >> a[i];
        if (f[a[i]]) {
            s[a[i]] = i;
        } else {
            f[a[i]] = i;
        }
    }
    for (int i=1;i<=n;i++) {
        if (abs(s[i]-f[i]) == 2) {
            ans++;
        }
    }
    cout << ans << endl;




    return 0;
}
