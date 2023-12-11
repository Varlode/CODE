/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e4+10;
int n, k, a[N], dp[N];

void solve() {
    cin >> n >> k;
    fill(dp+1, dp+1+n, (int) -1e9);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; i+j <= n && j <= k; j++) {
            dp[i+j] = max(dp[i+j], dp[i]+a[i+j]);
            ans = max(ans, dp[i+j]);
        }
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
