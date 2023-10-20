#include<bits/stdc++.h>
using namespace std;

const int maxN=1e3+9;
int n, m, u, v, a[maxN][maxN];

int main() {
    freopen("doicho.inp", "r", stdin);
    freopen("doicho.out", "w", stdout);
    cin >> m >> n >> u >> v;
    for (int i = 1; i <= m; i++) {
        int k = i; if (i == u) k = v; else if (i == v) k = u;
        for (int j = 1; j <= n; j++) {
            cin >> a[k][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++) cout << a[i][j] << ' '; cout << a[i][n] << endl;
    }
}