#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
int n, a, b, c;
int dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> a >> b >> c;
    dp[n] = 1;
    for (int i = n; i > 0; i--) {
        if (dp[i] == 0) continue;
        if (i>=a) dp[i-a] = max(dp[i-a], dp[i]+1);
        if (i>=b) dp[i-b] = max(dp[i-b], dp[i]+1);
        if (i>=c) dp[i-c] = max(dp[i-c], dp[i]+1);
    }
    cout << dp[0]-1;
}