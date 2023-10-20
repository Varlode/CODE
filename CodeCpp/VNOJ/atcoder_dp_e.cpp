#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, W, limit;
int w[110], v[110];
int dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        limit += v[i];
    }

    for (int i = 1; i <= limit; i++) dp[i] = W+1;

    for (int i = 1; i <= n; i++) {
        for (int j = limit; j > v[i]; j--) {
            if (dp[j - v[i]] + w[i] <= W) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
        dp[v[i]] = min(dp[v[i]], w[i]);
    }

    int ans = 0;
    for (int i = 0; i <= limit; i++) {
        if (dp[i] <= W) ans = i;
    }
    cout << ans;
}