#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, m, a[N], dp[N][110];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> m;

    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) for (int j = 1; j < i; j++) dp[i][j] = a[i]+a[j];
    for (int i = m + 1; i <= n; i++) for (int j = i - m + 1; j < i; j++) for (int k = i-m; k < j; k++)
        dp[i][i-j] = min(dp[i][i-j], dp[j][j-k] + a[i]);
    int ans = 0x3f3f3f3f;
    for (int i = n; i > n - m + 1; i--) for (int j = 1; i-j > n-m; j++)
        ans = min(ans, dp[i][j]);
    cout << ans;
}
