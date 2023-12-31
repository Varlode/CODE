/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    neu dinh nay ko bi pha
    thi xung quanh chac bi pha
    suy ra dinh bi pha phai cang xa 1 cang to
    -> xung quanh dinh ko bi pha chac chan bi pha moi toi uu


*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 3e4+1;
int n, m, k, ans, vis[N];
vector<int> adj[N];

void init(void) {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        int u; cin >> u;
        for (int v: adj[u]) vis[v] = 1;
    }
}

void solve(void) {
    queue<int> q;
    q.push(1);

    ans = n;
    while (q.size()) {
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1; ans--;
        for (int v: adj[u]) if (!vis[v]) q.push(v);
    }
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
