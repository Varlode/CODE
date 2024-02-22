/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    viec xac dinh thanh phan lien thong manh chinh la xac dinh chot cua no
    tuc la vi tri ma low[u] == num[u]

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
int timer, n, m, comp[N], num[N], low[N], ans;
vector<int> adj[N], s;

void init(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
}

void dfs(int u) {
    s.push_back(u);
    num[u] = low[u] = ++timer;
    for (int v: adj[u]) if (!comp[v]) {
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (num[u] == low[u]) {
        int v;
        ans++;
        do {
            v = s.back(); s.pop_back();
            comp[v] = ans;
        }
        while (v != u);
    }
}

void solve(void) {
    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i);
    cout << ans;
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
