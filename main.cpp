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
map<string,int> mp;
int a[MAX+1];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        string s;
        // 歌曲的名称, 播放时长
        cin >> s >> a[i];
        mp[s] = i;
    }
    // wowo听完这首歌后睡着
    string s1;
    cin >> s1;
    int start = mp[s1]+1;
    // 睡着时播放歌曲总时长
    int ans = 0;
    for (int i=start;i<=n;i++) {
        ans += a[i];
    }
    cout << ans << endl;


    return 0;
}

