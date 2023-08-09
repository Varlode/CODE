#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
long long n, m, a[maxN][maxN], x, y, u, v, ans = 1e13;

int main() {
    // freopen("cathinh.inp", "r", stdin);
    // freopen("cathinh.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    cin >> x >> y >> u >> v;
    
    for (int i = x; i < u; i++) {
        ans = min(ans, abs((a[u][v]-a[u][y-1]-a[i][v]+a[i][y-1])-(a[i][v]-a[i][y-1]-a[x-1][v]+a[x-1][y-1])));
        cout << abs((a[u][v]-a[u][y-1]-a[i][v]+a[i][y-1])-(a[i][v]-a[i][y-1]-a[x-1][v]+a[x-1][y-1])) << ' ';
    }
    cout << endl;
    for (int j = y; j < v; j++) {
        ans = min(ans, abs((a[u][v]-a[x-1][v]-a[u][j]+a[x-1][j])-(a[u][j]-a[x-1][j]-a[u][y-1]+a[x-1][y-1])));
        cout << abs((a[u][v]-a[x-1][v]-a[u][j]+a[x-1][j])-(a[u][j]-a[x-1][j]-a[u][y-1]+a[x-1][y-1])) << ' ';
    }
    cout << endl;
    cout << ans;
}