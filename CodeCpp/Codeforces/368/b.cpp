#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6;
int n, m, a[N], dp[N], mark[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        dp[i] = dp[i+1];
        if (mark[a[i]] == 0) dp[i]++;
        mark[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        int l; cin >> l;
        cout << dp[l] << '\n';
    }

}