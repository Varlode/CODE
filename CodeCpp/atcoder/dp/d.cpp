/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;
const int W = 1e6+1;

int n, w;
int a[N], c[N];
long long dp[W];

void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = w; j-a[i] >= 1; j--) if (dp[j-a[i]])
            dp[j] = max(dp[j], dp[j-a[i]]+c[i]);

        dp[a[i]] = max(dp[a[i]], 1ll*c[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= w; i++) ans = max(ans, dp[i]);
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
