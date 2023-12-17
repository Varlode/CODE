/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, a[N];
long long dp[N];

void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];
    dp[2] = a[2];
    dp[3] = a[2]+a[3];
    for (int i = 4; i <= n; i++) {
        dp[i] = min(dp[i-2], dp[i-1]) + a[i];
    }
    cout << dp[n];
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
