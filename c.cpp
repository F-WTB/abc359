#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

ll sx, sy, tx, ty;

ll f(ll a, ll b, ll c, ll d) {
    ll x = abs(a - c);
    ll y = abs(b - d);

    if (y >= x)
        return y;

    return y + (x - y + 1) / 2;
}

int main() {
    cin >> sx >> sy >> tx >> ty;

    if (sx & 1 ^ sy & 1)
        sx -= 1;
    if (tx & 1 ^ ty & 1)
        tx -= 1;

    cerr << sx << ' ' << sy << ' ' << tx << ' ' << ty << '\n';

    cout << f(sx, sy, tx, ty) << '\n';
}
