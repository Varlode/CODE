/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
const int MOD = 1e9+7;
int m, n, dp[N][N];

void solve() {
    cin >> m >> n;
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        char c; cin >> c;
        if (c == '.') {
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[m][n];
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
