/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 3e4+1;
int n, ans, lim;
int dp[N];
vector<int> adj[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        lim = max(lim, v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= lim; i++) {
        dp[i] = dp[i-1];
        for (int j: adj[i]) dp[i] = max(dp[i], dp[j]+i-j);
    }
    cout << dp[lim];
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
