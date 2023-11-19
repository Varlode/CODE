#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int dp[N], n, a[N], ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);   
    }
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] >= a[i-1]) dp[i] = dp[i-1]+1;
        else dp[i] = 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}