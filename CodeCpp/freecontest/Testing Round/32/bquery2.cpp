/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
int m, n, q;
int b[N*2][N*2], a[N][N];
char c[N][N];

int getA(int x, int y, int u, int v) {
    return a[u][v] - a[u][y-1] - a[x-1][v] + a[x-1][y-1];
}

int getB(int x, int y, int u, int v) {
    return b[(u-1)*2+1][(v-1)*2+1] - b[(x-1)*2][(v-1)*2+1]
            - b[(u-1)*2+1][(y-1)*2] + b[(x-1)*2][(y-1)*2];
}

int get(int x, int y, int u, int v) {
    return  getA(x, y, u, v)-getB(x, y, u, v);
}

void solve(void) {
    cin >> m >> n >> q;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> c[i][j];
        a[i][j] = c[i][j] == '1';
        a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        if (c[i][j] == '0') continue;
        if (i < m && c[i][j] == c[i+1][j]) b[i*2][(j-1)*2+1] = 1;
        if (j < n && c[i][j] == c[i][j+1]) b[(i-1)*2+1][j*2] = 1;
    }
    for (int i = 1; i < 2*m; i++) for (int j = 1; j < 2*n; j++)
        b[i][j] += b[i-1][j]+b[i][j-1]-b[i-1][j-1];

    for (int i = 1; i <= q; i++) {
        int x, y, u, v; cin >> x >> y >> u >> v;
        cout << get(x, y, u, v) << '\n';
    }

}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
