#include<bits/stdc++.h>
using namespace std;

int x[209], n, k, a, b, ans = 1e9+9;
int dp[200][200];

int main() {
    cin >> n >> k >> a >> b;
    for (int i = 1; i <= n; i++) 
        cin >> x[i];

    for (int i = 1; i <= n; i++) {
        for (int j = max(i-b, 0); j <= i-a; j++) {
            for (int cnt = 1; cnt <= k; cnt++) {
                dp[i][cnt] = max(dp[j][cnt-1], x[i]-x[j+1]);
            }
        }
    }
    cout << dp[n][k] << endl;
}