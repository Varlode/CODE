    #include <bits/stdc++.h>
    using namespace std;

    const int N = (int) 1000100;
    int n, dp[N];

    void pre(void) {
        dp[0] = 1;
        for (int i = 2020; i <= (int) 1e6; i++) {
            dp[i] = dp[i-2021] || dp[i-2020];
        }
        dp[0] = 0;
    }

    void solve(void) {
        cin >> n; 
        cout << (dp[n]? "YES\n": "NO\n");
    }

    int main(void) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        #define TASK "TASK"
        if (fopen(TASK".inp", "r")) {
            freopen(TASK".inp", "r", stdin);
            freopen(TASK".out", "w", stdout);
        }
        int t; cin >> t;
        pre();
        while (t--) solve();
    }