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
int n, m, dp[N];
vector<int> adj[N];

void dfs(int u) {
    if (dp[u]) return;
    for (int v: adj[u]) {
        dfs(v);
        dp[u] = max(dp[u], dp[v]);
    }
    dp[u]++;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dfs(i);
        ans = max(ans, dp[i]-1);
    }
    cout << ans;
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
