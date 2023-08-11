#include<bits/stdc++.h>
using namespace std;

int n, m, a[1009][1009], x, y;

int main() {
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) a[i][0] = 1e9;
    for (int i = 1; i <= n; i++) a[0][i] = 1e9;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] += min(a[i-1][j-1], min(a[i-1][j], a[i][j-1]));
        }
    }
    cin >> x >> y;
    cout << a[x][y];
}