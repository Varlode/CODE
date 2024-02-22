/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    nen do thi thanh cay DAG, bang cach nen TPLT manh thanh 1 dinh
    roi tu do DP tren DAG

    viec dfs de dp tren DAG, nen luu y viec tinh roi thi ko nen tinh nua

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
int n, m, a[N], num[N], low[N], comp[N], val[N], dp[N], timer, scc;
char c[N];
vector<int> adj[N], adj_scc[N], s;

void init(void) {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        int u = (i-1)*n+j;
        cin >> c[u];
    }
}

void preDfs(int u) {
    s.push_back(u);
    num[u] = low[u] = ++timer;
    for (int v: adj[u]) if (!comp[v]) {
        if (!num[v]) {
            preDfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if (num[u] == low[u]) {
        int v;
        scc++;
        do {
            v = s.back(); s.pop_back();
            comp[v] = scc;
            val[scc] += a[v];
        } while (v != u);
    }
}

void dfs(int u) {
    int res = 0;
    dp[u] = val[u];
    for (int v: adj_scc[u]) {
        if (dp[v] == -1) dfs(v);
        res = max(res, dp[v]);
    }
    dp[u] += res;
}

void solve(void) {
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        int u = (i-1)*n+j;
        if (c[u] == '#') continue;
        if ('0' <= c[u] && c[u] <= '9') a[u] = c[u]-'0';
        if (j < n && c[u+1] != '#') adj[u].push_back(u+1);
        if (i < m && c[u+n] != '#') adj[u].push_back(u+n);
        if (c[u] == 'W' && j > 1 && c[u-1] != '#') adj[u].push_back(u-1);
        if (c[u] == 'N' && i > 1 && c[u-n] != '#') adj[u].push_back(u-n);
    }

    preDfs(1);

    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        int u = (i-1)*n+j;
        for (int v: adj[u]) if (comp[u] != comp[v]) {
            adj_scc[comp[u]].push_back(comp[v]);
        }
    }
    memset(dp, -1, sizeof dp);
    dfs(scc);
    cout << dp[scc];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    init();
    solve();
}
