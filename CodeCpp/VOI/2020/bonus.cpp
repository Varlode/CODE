/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 301;
int a[N], pref[N];
long long dp[N][N][151];

long long calc(int l, int r, int k) {
    if (dp[l][r][k]) return dp[l][r][k];
    if (k == 0 || 2*k > r-l+1) return dp[l][r][k] = 0;
    if (r-l+1 == 2 && k == 1) return dp[l][r][k] = abs(a[l]-a[r]);
    long long ans = 0;
    ans = max(ans, calc(l+2, r, k-1)+abs(a[l]-a[l+1]));
    ans = max(ans, calc(l, r-2, k-1)+abs(a[r-1]-a[r]));
    ans = max(ans, calc(l+1, r-1, k-1)+abs(a[l]-a[r]));
    ans = max(ans, calc(l+1, r, k));
    ans = max(ans, calc(l, r-1, k));
    return dp[l][r][k] = ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << calc(1, n, k);
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
