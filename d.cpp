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

int N, K;
string S;

mint dp[1001][1 << 9];
bool b[1 << 10];

int main() {
    cin >> N >> K >> S;

    for (int x = 0; x < 1 << K; ++x)
        for (int i = 0; i < K; ++i)
            if (!(x & 1 << i) ^ !(x & 1 << K - 1 - i))
                b[x] = 1;

    for (int x = 0; x < 1 << K - 1; ++x) {
        bool flag = 1;
        for (int i = 0; i < K - 1; ++i)
            if (S[K - 2 - i] == 'A' && (x & 1 << i) != 0 || S[K - 2 - i] == 'B' && (x & 1 << i) == 0) flag = 0;
        if (flag) dp[K - 1][x] = 1;
    }

    int mask = (1 << K - 1) - 1;

    for (int i = K - 1; i < N; ++i) {
        if (S[i] != 'B')
            for (int x = 0; x < 1 << K - 1; ++x) {
                int y = x << 1;
                if (b[y])
                    dp[i + 1][y & mask] += dp[i][x];
            }
        if (S[i] != 'A')
            for (int x = 0; x < 1 << K - 1; ++x) {
                int y = x << 1 | 1;
                if (b[y])
                    dp[i + 1][y & mask] += dp[i][x];
            }
    }
    mint ans = 0;
    for (int x = 0; x < 1 << K - 1; ++x)
        ans += dp[N][x];
    cout << ans << '\n';
}
