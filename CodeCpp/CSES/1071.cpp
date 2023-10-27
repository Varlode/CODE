#include <bits/stdc++.h>
using namespace std;

int n, dp[1010], t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[1] = 1;
    for (int i = 2; i <= 1e3; i++) dp[i] = dp[i-1]+(i-1)*2;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x, y; cin >> x >> y;
        if (x == y) {
            cout << dp[x] << endl;
            continue;
        }
        if (x > y)
        if (x&1) cout << dp[x]-abs(x-y) << endl;
        else cout << dp[x]+abs(x-y) << endl;
        else 
        if (y&1) cout << dp[y]+abs(x-y) << endl;
        else cout << dp[y]-abs(x-y) << endl;
    }

}