/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    qhd bit mask
    dp[i][mask] la tai thanh pho i cua trang thai la mask

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

int n, c[20][20];
int dp[20][1 << 20];

void solve(void) {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> c[i][j];

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < n; i++) dp[i][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) if ((mask >> i) & 1) {
            for (int j = 0; j < n; j++) if ((mask >> j) & 1) {
                dp[i][mask] = min(dp[i][mask], dp[j][mask & ~(1 << i)] + c[j][i]);

            }
        }
    }

    int res = 1e9;
    for (int i = 0; i < n; i++) res = min(res, dp[i][(1 << n)-1]);
    cout << res;
}

int main(void) {
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
