/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int N = 101010;
int n, m;
int h[N];
int par[N][21], mn[N][21];
vector< ii > adj[N];
vector< pair<int, ii> > edge, query;

int lab[N];

void make_dsu() {
    for (int i = 1; i <= n; i++) lab[i] = -1;
}

int find(int u) {
    return lab[u] < 0? u: lab[u] = find(lab[u]);
}

bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }
    return false;
}

void dfs(int u) {
    for (ii &p: adj[u]) {
        int v = p.fi, w = p.se;
        if (v == par[u][0]) continue;

        par[v][0] = u; mn[v][0] = w;
        h[v] = h[u]+1;

        for (int i = 1; i <= 20; i++) {
            par[v][i] = par[par[v][i-1]][i-1];
            mn[v][i] = min(mn[v][i-1], mn[par[v][i-1]][i-1]);
        }
        dfs(v);
    }
}

int lca(int u, int v) {
    int res = 1e9;
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u]-h[v];
        for (int i = 20; i >= 0; i--) if ((k >> i) & 1) {
            res = min(res, mn[u][i]);
            u = par[u][i];
        }
    }
    if (u == v) return res;

    for (int i = 20; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            res = min(res, mn[u][i]);
            res = min(res, mn[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    res = min(res, mn[u][0]);
    res = min(res, mn[v][0]);
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }

    make_dsu();
    sort(edge.begin(), edge.end(), greater< pair<int, ii> >());
    for (pair<int, ii> p: edge) {
        int u = p.se.fi, v = p.se.se, w = p.fi;
        if (join(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        else query.push_back(p);
    }

    dfs(1);

    int ans = 0;
    for (pair<int, ii> &p: query) {
        int u = p.se.fi, v = p.se.se, w = p.fi;
        ans += lca(u, v)-w;
    }
    cout << ans;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "upgradenet"
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
