/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define _pii pair<int, int>
#define edge pair<int, _pii>

const int N = 1010;
int d[N], h[N], n, q;
int par[N][21];
vector<_pii> adj[N];

void dfs(int u, int pa = -1) {
    for (_pii p: adj[u]) {
        int v = p.first, w = p.second;
        if (v == pa) continue;
        d[v] = d[u]+w;
        h[v] = h[u]+1;
        par[v][0] = u;
        for (int i = 1; i <= 20; i++)
            par[v][i] = par[par[v][i-1]][i-1];
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int len = h[u] - h[v];
        for (int i = 0; (1 << i) <= len; i++) {
            if ((len >> i)&1) u = par[u][i];
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

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        cout << d[u] + d[v] - 2*d[LCA(u, v)] << '\n';
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
