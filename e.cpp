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

int N, H;

ll sum = 0;
stack<pr> v;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> H;
        sum += H;
        int w = 1;
        while (v.size() && v.top().first < H) {
            sum += ll(H - v.top().first) * v.top().second;
            w += v.top().second;
            v.pop();
        }
        v.emplace(H, w);
        cout << sum + 1 << (i < N - 1 ? '\t' : '\n');
    }
}
