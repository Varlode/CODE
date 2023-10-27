#include <bits/stdc++.h>
using namespace std;

const int N = 2020;
int m, n, p, q, u, v, x, y;
long long a[N][N];

long long get(int x, int y, int u, int v) {
    return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("tinhtien2d.inp", "r", stdin);
    freopen("tinhtien2d.out", "w", stdout);
    cin >> m >> n >> p >> q >> x >> y >> u >> v;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        a[i+m][j] = a[i][j+n] = a[i+m][j+n] = a[i][j];
    }
    for (int i = 1; i <= 2*m; i++) for (int j = 1; j <= 2*n; j++) {
        a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
    }
    p %= m; if (p == 0) p = m;
    q %= n; if (q == 0) q = n;
    x += p; u += p; y += q; v += q;
    cout << get(x, y, u, v);
}