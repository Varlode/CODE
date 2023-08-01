#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
long long a[maxN][maxN];
int m, n;

int main() {
    freopen("duongdi.inp", "r", stdin);
    freopen("duongdi.out", "w", stdout);
    cin >> m >> n;
    for (int i = 2; i <= n; i++) a[0][i] = 1e8;
    for (int i = 2; i <= m; i++) a[i][0] = 1e8;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] += min(a[i-1][j], a[i][j-1]);
        }
    }
    cout << a[m][n];
}