/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 31;
int m, n, a[N][N], dp[N][N][N][N];

int cut(int x, int y, int u, int v) {
    if (dp[x][y][u][v] != -1) return dp[x][y][u][v];

    int cnt = 0;
    for (int i = x; i <= u; i++) for (int j = y; j <= v; j++) {
        cnt += a[i][j];
    }
    if (cnt == (u-x+1)*(v-y+1) || cnt == 0) {
        return dp[x][y][u][v] = 1;
    }

    int mn = 1e9;

    // cat doc
    for (int k = y; k < v; k++) {
        mn = min(mn, cut(x, y, u, k) + cut(x, k+1, u, v));
    }

    // cat ngang
    for (int k = x; k < u; k++) {
        mn = min(mn, cut(x, y, k, v) + cut(k+1, y, u, v));
    }

    return dp[x][y][u][v] = mn;
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        cin >> a[i][j];

    memset(dp, -1, sizeof dp);
    cut(1, 1, m, n);
    cout << dp[1][1][m][n];
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
