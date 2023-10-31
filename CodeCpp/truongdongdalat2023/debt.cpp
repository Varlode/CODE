#include <bits/stdc++.h>
using namespace std;

int n, l, r, k;
int a[1010];    
int dpR[110][110][2510], dpL[110][110][2510];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dpR, 0, sizeof dpR);
    memset(dpL, 0, sizeof dpL);
    freopen("debt.inp", "r", stdin);
    freopen("debt.out", "w", stdout);
    cin >> n >> l >> r >> k;
    k = min(k, n*n/4);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < l; i++) 
        for (int j = l; j <= r; j++) 
            for (int t = 0; t <= k; t++) {
                dpL[i][j][t] = min(dpL[i][j][t], dpL[i-1][j][t]);
                dpL[i][j][t] = min(dpL[i][j][t], dpL[i][j-1][t]);
                dpL[i][j][t] = min(dpL[i][j][t], dpL[i][j][t-1]);
                if (t >= abs(i-j)) dpL[i][j][t] = min(dpL[i][j][k], dpL[i-1][j-1][t-abs(i-j)] + a[i] - a[j]); 
            }
        
    for (int i = n; i > r; i--) 
        for (int j = r; j >= l; j--) 
            for (int t = 0; t <= k; t++) {
                dpR[i][j][t] = min(dpR[i][j][t], dpR[i+1][j][t]);
                dpR[i][j][t] = min(dpR[i][j][t], dpR[i][j+1][t]);
                dpR[i][j][t] = min(dpR[i][j][t], dpR[i][j][t-1]);
                if (t >= abs(i-j)) dpR[i][j][t] = min(dpR[i][j][t], dpR[i+1][j+1][t-abs(i-j)] + a[i] - a[j]); 
            }

    long long sum = 0, ans = 1e9;
    for (int i = l; i <= r; i++) sum += a[i];

    for (int i = l-1; i <= r+1; i++) 
        for (int t = 0; t <= k; t++) {
            ans = min(ans, sum + dpL[l-1][i-1][t] + dpR[r+1][i][k-t]);
        }   
    cout << ans;
}
