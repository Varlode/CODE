#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
const int inf = 1e9;
int n, m, b, k, s, t, h[N], par[N][21], mn[N][21];
pair<int, pair<int, int>> e[N];
vector<pair<int, int>> adj[N], queries;
vector<int> ans, tmp;

struct DSU {
    int lab[N];

    DSU() {
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
};

inline void make_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void pre_dfs(int u, int p) {
    for (auto it: adj[u]) {
        int v = it.first, w = it.second;
        if (v == p) continue;
        par[v][0] = u;
        mn[v][0] = w;
        h[v] = h[u]+1;
        pre_dfs(v, u);
    }
}

bool dfs(int u, int p) {
    tmp.push_back(u);
    if (u == s) {
        k = tmp.size();
        for (int i: tmp) ans.push_back(i);
        return true;
    }
    for (auto it: adj[u]) {
        int v = it.first, w = it.second;
        if (v == p) continue;
        if (dfs(v, u)) return true;
    }
    tmp.pop_back();
    return false;
}

void pre_lca() {
    for (int j = 1; j <= 19; j++) for (int i = 1; i <= n; i++) {
        par[i][j] = par[par[i][j-1]][j-1];
        mn[i][j] = min(mn[i][j-1], mn[par[i][j-1]][j-1]);
    }
}

int lca(int u, int v) {
    int res = inf;

    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 19; i >= 0; i--) if ((k >> i) & 1) {
            res = min(res, mn[u][i]);
            u = par[u][i];
        }
    }

    if (u == v) return res;

    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            res = min({res, mn[u][i], mn[v][i]});
            u = par[u][i];
            v = par[v][i];
        }
    }
    res = min({res, mn[u][0], mn[v][0]});
    return res;
}

void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[i].first = w;
        e[i].second.first = u;
        e[i].second.second = v;
    }
    sort(e+1, e+1+m);

    ans.clear(); queries.clear(); tmp.clear();
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) h[i] = 0;
    DSU my_dsu;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        u = e[i].second.first; v = e[i].second.second;
        w = e[i].first;
        if (my_dsu.join(u, v)) make_edge(u, v, w);
        else queries.push_back({u, v});
    }

    for (int i = 1; i <= n; i++)
        if (h[i] == 0) pre_dfs(i, 0);
    pre_lca();

    int id = 0; b = inf;
    for (int i = 0; i < (int) queries.size(); i++) {
        int u = queries[i].first, v = queries[i].second;
        int res = lca(u, v);
        if (res < b) {
            id = i;
            b = res;
        }
    }
    s = queries[id].second;
    dfs(queries[id].first, 0);

    cout << b << ' ' << k << '\n';
    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
