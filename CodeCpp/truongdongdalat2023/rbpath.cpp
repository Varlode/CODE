#include <bits/stdc++.h>
using namespace std;

const int N = 200200;
int n, m;

int dp[N][2], daDi[N][2], laChuTrinh[N][2];

vector<int> adj[N][2];

int dfs(int u, int c) {
    if (daDi[u][c]) return dp[u][c];
    dp[u][c] = 0;
    daDi[u][c] = 1;
    for (int v: adj[u][1-c])
        dp[u][c] = max(dp[u][c], dfs(v, 1-c) + 1);
    return dp[u][c];
}

int coPhaiChuTrinh(int u, int c) {
    if (daDi[u][c] == 2) return laChuTrinh[u][c];
    daDi[u][c] = 1;
    for (int v: adj[u][1-c]) {
        if (!daDi[v][1-c]) {
            if (coPhaiChuTrinh(v, 1-c)) return laChuTrinh[u][c] = true;
        } else if (daDi[v][1-c] == 1) return laChuTrinh[u][c] = true;
    }
    daDi[u][c] = 2;
    return laChuTrinh[u][c] = false;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w; w--;
        adj[u][w].push_back(v); 
    }
    for (int i = 1; i <= n; i++) {
        coPhaiChuTrinh(i, 0);
        coPhaiChuTrinh(i, 1);
    }
    memset(daDi, 0, sizeof daDi);

    for (int i = 1; i <= n; i++) {
        if (laChuTrinh[i][0] || laChuTrinh[i][1]) cout << -1 << endl;
        else cout << max(dfs(i, 0), dfs(i, 1)) << endl;
    }
}  

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "d13rbpath"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    solve();
}