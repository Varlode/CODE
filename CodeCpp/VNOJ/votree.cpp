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
int n, m, h[N], par[N][21], spatab[N][21];
vector< int > adj[N];

void dfs(int u) {
    for (int v: adj[u]) if (v != par[u][0]) {
        h[v] = h[u]+1;
        par[v][0] = u;
        for (int j = 1; j <= 20; j++)
            par[v][j] = par[par[v][j-1]][j-1];
        dfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 0; i <= 20; i++) if ((k >> i) & 1) {
            u = par[u][i];
        }
    }
    if (u == v) return u;

    for (int i = 20; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int get(int l, int r) {
    int k = __lg(r-l+1);
    return lca(spatab[l][k], spatab[r-(1<<k)+1][k]);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    for (int i = 1; i <= n; i++) spatab[i][0] = i;
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i+(1 << (j-1)) <= n; i++) {
            spatab[i][j] = lca(spatab[i][j-1], spatab[i+(1 << (j-1))][j-1]);

        }

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        cout << get(u, v)<< '\n';
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
