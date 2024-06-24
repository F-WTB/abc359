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

int N, A[200000];
vector<int> g[200000];
map<int, vector<int>> mp;

int c[200000];
ll s[200000];

ll ans = 0;
void dfs(int v, int p, int x) {
    c[v] = 0, s[v] = 0;
    for (int nv : g[v]) {
        if (nv == p) continue;
        dfs(nv, v, x);
        c[v] += c[nv];
        s[v] += s[nv];
    }

    for (int nv : g[v]) {
        if (nv == p) continue;
        ans += s[nv] * (c[v] - c[nv]);
    }

    if (A[v] == x) {
        ans += s[v];
        ++c[v];
    }

    s[v] += c[v];
}

int a[20][200000], d[200000];
void dfs2(int v, int p) {
    a[0][v] = p;
    for (int nv : g[v]) {
        if (nv == p) continue;
        d[nv] = d[v] + 1;
        dfs2(nv, v);
    }
}

int lca(int i, int j) {
    if (d[i] > d[j]) swap(i, j);
    int dd = d[j] - d[i];
    for (int k = 0; k < 20; ++k)
        if (dd & 1 << k)
            j = a[k][j];

    for (int k = 20 - 1; k >= 0; --k)
        if (a[k][i] != a[k][j]) i = a[k][i], j = a[k][j];
    return a[0][i];
}

int dist(int i, int j) {
    return d[i] + d[j] - d[lca(i, j)] * 2;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs2(0, 0);
    for (int k = 0; k < 19; ++k)
        for (int i = 0; i < N; ++i)
            a[k + 1][i] = a[k][a[k][i]];

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        mp[A[i]].push_back(i);
    }

    for (auto [k, v] : mp) {
        int M = v.size();
        if ((ll)M * M < N)
            for (int i = 0; i < M - 1; ++i)
                for (int j = i + 1; j < M; ++j)
                    ans += dist(v[i], v[j]);
        else dfs(0, 0, k);
    }

    cout << ans << '\n';
}
