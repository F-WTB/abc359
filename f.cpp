#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<ll, int>;
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

int N, A[200000], k[200000];
ll ans = 0;

ll cost(int i) {
    return (ll)A[i] * (k[i] * 2 + 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A, A + N);

    priority_queue<pr> pq;
    pq.emplace(-A[0], 0);
    for (int i = 1; i < N; ++i) {
        int id = pq.top().second;
        pq.pop();
        ans += cost(id);
        ++k[id];
        ans += cost(i);
        ++k[i];
        pq.emplace(-cost(id), id);
        pq.emplace(-cost(i), i);
    }
    cout << ans << '\n';
}
