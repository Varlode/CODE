#include<bits/stdc++.h>
using namespace std;

const int maxN=109;
int n, m, l, ans = 0;
int x[maxN], y[maxN], u[maxN], v[maxN], k[maxN], bf[maxN][maxN], af[maxN][maxN];

int main() {
    freopen("windows.inp", "r", stdin);
    freopen("windows.out", "w", stdout);
    cin >> n >> m >> l;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> u[i] >> v[i];
        x[i]++; y[i]++; u[i]++; v[i]++;
    }
    int f;
    for (int i = 1; i <= m; i++) { 
        cin >> k[i];
        if (k[i] == l) f = i;
    }
    bf[x[l]][y[l]] += 1;
    bf[x[l]][v[l]+1] -= 1;
    bf[u[l]+1][y[l]] -= 1;
    bf[u[l]+1][v[l]+1] += 1;
    for (int i = f+1; i <= m; i++) {
        af[x[k[i]]][y[k[i]]] += 1;
        af[x[k[i]]][v[k[i]]+1] -= 1;
        af[u[k[i]]+1][y[k[i]]] -= 1;
        af[u[k[i]]+1][v[k[i]]+1] += 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bf[i][j] += bf[i-1][j]+bf[i][j-1]-bf[i-1][j-1];
            af[i][j] += af[i-1][j]+af[i][j-1]-af[i-1][j-1];
            if (bf[i][j] > af[i][j] ) ans++;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << bf[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "===================" << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << af[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << ans;
}