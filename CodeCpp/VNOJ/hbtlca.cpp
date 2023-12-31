/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, m, h[N], par[N][21];
vector<int> adj[N];

void dfs(int u) {
    for (int v: adj[u]) if (v != par[u][0]){
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
        for (int i = 0; i <= 20; i++) if ((k >> i) & 1)
            u = par[u][i];
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

void solve() {
    cin >> n;
    if (n == 0) return;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int root = 1;

    cin >> m;
    for (int i = 1; i <= m; i++) {
        char c; cin >> c;
        if (c == '!') cin >> root;
        if (c == '?') {
            int u, v; cin >> u >> v;
            int ur = lca(u, root);
            int vr = lca(v, root);
            int uv = lca(u, v);
            cout << (ur ^ vr ^ uv) << '\n';
        }
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
    while (t) {
        solve();
        if (n == 0) break;
    }
}
