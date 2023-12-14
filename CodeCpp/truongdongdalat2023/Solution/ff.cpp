#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}
const int N = 1e4+5, M = 105, INF = 1e18;
int n, m;
int a[N];
int dp[N][M];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    memset(dp, 0x3f, sizeof dp);
    for (int i = 2; i <= m; ++i)
        for (int j = 1; j < i; ++j)
            dp[i][i - j] = a[i] + a[j];
    /*
    dp[i][j]:
    chọn thỏa mãn đoạn [1..i], 2 món được chọn cuối cùng nằm ở vị trí i và i - j
    */
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j < m && i - j > 0; ++j) {
            if (dp[i][j] > INF) continue;
            /*
            đã chọn i và i - j thì vị trí tiếp theo phải nằm trong đoạn
            i + 1 .. i - j + m
            */
            int x = min(i - j + m, n);
            for (int k = i + 1; k <= x; ++k) {
                mini(dp[k][k - i], dp[i][j] + a[k]);
            }
        }
    }

    // for (int i = 2; i <= n; ++i)
    //     for (int j = 1; j < m && i - j > 0; ++j)
    //         cout << i << ' ' << j << ' ' << dp[i][j] << '\n';

    int ans = 1e18;
    int x = n - m + 1;
    for (int i = x + 1; i <= n; ++i) {
        for (int j = x; j < i; ++j) {
            mini(ans, dp[i][i - j]);
        }
    }
    cout << ans;
    return 0;
}
