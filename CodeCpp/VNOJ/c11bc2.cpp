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
#define i2 pair<int, int>

const int N = 1e4+100;
int n, q, h[N];

vector< i2 > adj[N];
i2 par[N][22];

void dfs(int u) {
    for (i2 &p: adj[u]) {
        int v = p.fi, w = p.se;
        if (v == par[u][0].fi) continue;

        par[v][0].fi = u;
        par[v][0].se = w;
        h[v] = h[u]+1;

        for (int i = 1; i <= 16; i++) {
            par[v][i].fi = par[par[v][i-1].fi][i-1].fi;
            par[v][i].se = max(par[v][i-1].se, par[par[v][i-1].fi][i-1].se);
        }
        dfs(v);
    }
}

int lca(int u, int v) {
    int res = 1;
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 16; i >= 0; i--) if ((k >> i) & 1) {
            res = max(res, par[u][i].se);
            u = par[u][i].fi;
        }
    }
    if (u == v) return res;

    for (int i = 16; i >= 0; i--) {
        if (par[u][i].fi != par[v][i].fi) {
            res = max({res, par[u][i].se, par[v][i].se});
            u = par[u][i].fi;
            v = par[v][i].fi;
        }
    }
    res = max({res, par[u][0].se, par[v][0].se});
    return res;
}

void solve() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x, w; cin >> x >> w;
        adj[i].push_back({x, w});
        adj[x].push_back({i, w});
    }

    dfs(1);
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        if (lca(u, v) == 2) cout << "YES\n";
        else cout << "NO\n";
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
