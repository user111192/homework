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
#include <ctime>
#include <iomanip>
#include <thread>


#ifdef LOCAL

#include "basic_string_plus.h"
#include "dsu.h"

#endif
#if __cplusplus >= 202002L

#include <compare>

#endif
#if __cplusplus >= 201702L

#include <execution>

#endif


using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
[[maybe_unused]] constexpr int N = 300010;
[[maybe_unused]] constexpr int inf = (1 << 30);
[[maybe_unused]] constexpr ll inf_ll = (1ll << 60);
[[maybe_unused]] constexpr int MOD = 1000000007;


constexpr ll qpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}


int rpow(int base, int exp) {
    return qpow(base, exp);
}


namespace MyHash {
    const int base = 131;
    int memory[N];

    int Hash(int x) {
        // hash - integer
        return x % MOD;
    }

    int Hash(const string &s) {
        // hash - C++ string
        const int base = 131; // prime
        int val = 0, len = s.size();
        for (int i = 0; i < len; i++)
            val = (val * base + s[i]) % MOD, memory[i + 1] = val;
        return val;
    }

    int Hash(const char *s) {
        // hash - null-terminated string (C string)
        int val = 0, len = strlen(s);
        for (int i = 0; i < len; i++)
            val = (val * base + s[i]) % MOD, memory[i + 1] = val;
        return val;
    }

    int HashSubstring(int L, int R) {
        int t = (memory[L] * rpow(base, R - L + 1)) % MOD;
        return (memory[R + 1] - t + MOD) % MOD;
    }
}

namespace UnionFind {
    int fa[N], size, setcnt = 0;

    void init(int n) {
        size = n;
        setcnt = n;
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }

    int Findset(int x) {
        return (x == fa[x]) ? x : (fa[x] = Findset(fa[x]));
    }

    bool SameSet(int x, int y) {
        return Findset(x) == Findset(y);
    }

    bool merge(int x, int y) {
        int fx = Findset(x), fy = Findset(y);
        if (fx == fy) return false;
        setcnt--;
        fa[fx] = fy;
        return true;
    }

    int CountSet() {
        return setcnt;
    }
}


template<typename T>
constexpr T &chmax(T &a, const T &b) {
    return a = max(a, b);
}

template<typename T>
constexpr T &chmin(T &a, const T &b) {
    return a = min(a, b);
}

#define PYESNO(condition) {cout << ((condition) ? "YES" : "NO") << '\n';return;}
#define PYES() PYESNO(1)
#define PNO() PYESNO(0)
#define PYesNo(condition) {cout << ((condition) ? "Yes" : "No") << '\n';return;}
#define PYes() PYesNo(1)
#define PNo() PYesNo(0)

template<typename I>

#if __cplusplus >= 202002L
requires integral<I>
#endif

constexpr bool in_range(I x, I l, I r) {
    return l <= x && x <= r;
}

template<typename I>

#if __cplusplus >= 202002L
requires integral<I>
#endif

constexpr bool out_of_range(I x, I l, I r) {
    return !in_range(x, l, r);
}

//template<typename Cont>
//int sizei(const Cont& vv) {
//    return (int) std::size(vv);
//}


template<typename V>
void read(V &v) {
    for (auto &x: v)
        cin >> x;
}

#if __cplusplus >= 202002L
template<typename T>
concept is_writeable = requires(istream is, T x) {
    { is >> x } -> same_as<istream &>;
};

template<is_writeable T>
void read(T &x) {
    cin >> x;
}


template<typename T>
void reads(T &x) {
    read(x);
}

template<typename T, typename... Ts>
void reads(T &x, Ts &... rest) {
    read(x);
    reads(rest...);
}

#if __cplusplus >= 202002L
#define input_iterator_if_cxx20 input_iterator
#else
#define input_iterator_if_cxx20 typename
#endif

template<input_iterator_if_cxx20 InputIterator>
istream &readit(InputIterator begin, InputIterator end, istream &is = std::cin) {
    for (; begin != end; ++begin)
        is >> *begin;
    return is;
}

#endif

#define DNotNull(x) (assert((x)!=nullptr && #x " should not be null"),x)
#define ENotNull(x) assert((x)!=nullptr && #x " should not be null")


const char *max(const char *s1, const char *s2) {
    if (s1 == nullptr && s2 == nullptr) {
        assert(0 && "s1 和 s2 都为空");
        return nullptr;
    }
    if (s1 == nullptr) return s2;
    if (s2 == nullptr) return s1;
    return strcmp(s1, s2) > 0 ? s1 : s2;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

[[maybe_unused]] ll randint64(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng64);
}


#define rep(II, S, E) for(decltype(S+0) II=(S),__=(E);II<=__;II++)
#define repd(II, S, E) for(decltype(S+0) II=(S),__=(E);II>=__;II--)
#define PRINTLN(x) cout<<(x)<<endl
#define PRINTLB(x) {cout<<(x)<<endl;break;}
#define PRINTLC(x) {cout<<(x)<<endl;continue;}
#define PRINTLT(x) {cout<<(x)<<endl;return;}
#define PRINTLT0(x) {cout<<(x)<<endl;return 0;}


void solve() {

}



// #include "competitive.h"

int32_t main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    {
        // setup code
    }
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}