/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
int dp[N][N];

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = "~"+s;
    t = "~"+t;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        if (s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
    }
    cout << dp[n][m];
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
