/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ii pair<int, int>

const int N = 1e5+1;
int n, m, h[N], mx[N][21], mn[N][21], par[N][21];
vector< ii > adj[N];

void dfs(int u) {
    for (auto &p: adj[u]) {
        int v = p.fi, w = p.se;
        if (v == par[u][0]) continue;
        h[v] = h[u]+1;
        par[v][0] = u;
        mn[v][0] = mx[v][0] = w;

        for (int j = 1; j <= 20; j++) {
            par[v][j] = par[par[v][j-1]][j-1];
            mn[v][j] = min(mn[v][j-1], mn[par[v][j-1]][j-1]);
            mx[v][j] = max(mx[v][j-1], mx[par[v][j-1]][j-1]);
        }
        dfs(v);
    }
}

ii lca(int u, int v) {
    int res_mn = 1e9, res_mx = 0;
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 0; i <= 20; i++) if ((k >> i) & 1) {
            res_mn = min(res_mn, mn[u][i]);
            res_mx = max(res_mx, mx[u][i]);
            u = par[u][i];
        }
    }
    if (u == v) return ii(res_mn, res_mx);

    for (int i = 20; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            res_mn = min({res_mn, mn[u][i], mn[v][i]});
            res_mx = max({res_mx, mx[u][i], mx[v][i]});
            u = par[u][i];
            v = par[v][i];
        }
    }
    res_mn = min({res_mn, mn[u][0], mn[v][0]});
    res_mx = max({res_mx, mx[u][0], mx[v][0]});
    return ii(res_mn, res_mx);
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        ii res = lca(u, v);
        cout << res.fi << ' ' << res.se << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
