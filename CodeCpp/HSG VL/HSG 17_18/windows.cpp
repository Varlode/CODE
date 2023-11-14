#include<bits/stdc++.h>
using namespace std;

const int maxN=1010;
int n, m, l, ans = 0;
int x[maxN], y[maxN], u[maxN], v[maxN], k[maxN], a[maxN][maxN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cin >> n >> m >> l;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> u[i] >> v[i];
    }
    int f;
    for (int i = 1; i <= m; i++) { 
        cin >> k[i];
        if (k[i] == l) f = i;
    }
    for (int i = f+1; i <= m; i++) {
        a[x[k[i]]][y[k[i]]] += 1;
        a[x[k[i]]][v[k[i]]+1] -= 1;
        a[u[k[i]]+1][y[k[i]]] -= 1;
        a[u[k[i]]+1][v[k[i]]+1] += 1;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
    }
    for (int i = x[l]; i <= u[l]; i++) for (int j = y[l]; j <= v[l]; j++) {
        if (a[i][j] == 0) ans++;
    }
    cout << ans;
}