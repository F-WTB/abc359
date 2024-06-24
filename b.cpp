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

int N, A;
vector<int> v[100];

int main() {
    cin >> N;
    for (int i = 0; i < N * 2; ++i) {
        cin >> A;
        v[A - 1].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (v[i][0] + 2 == v[i][1]) ++ans;
    cout << ans << '\n';
}
