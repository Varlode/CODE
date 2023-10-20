#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+100;
int n, m, k, a[N][N];

int ans = -0x3f3f3f3f;

int main() {
    freopen("caycanh.inp", "r", stdin);
    freopen("caycanh.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] = a[i][j] + a[i][j-1] + a[i-1][j] - a[i-1][j-1];
        }
    for (int i = k; i <= m; i++) 
        for (int j = k; j <= n; j++)
            ans = max(ans, a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]);

    cout << ans;
}