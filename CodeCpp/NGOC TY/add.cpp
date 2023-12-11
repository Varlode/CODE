/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, k, dp[N][N];

void solve() {
    if (n == 0 && k == 0) return;
    if (k <= 1) {
        cout << k << '\n';
        return;
    }
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][1] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; i+j <= n; j++)
            for (int g = 1; g <= k; g++) {
                dp[i+j][g] += dp[i][g-1];
                dp[i+j][g] %= 1000000000;
            }
    cout << dp[n][k] - dp[n][k-1] + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "add"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (cin >> n >> k) {
        solve();
    }
}
