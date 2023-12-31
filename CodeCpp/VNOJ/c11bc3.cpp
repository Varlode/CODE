/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    co the dung 4 for
    tinh prefix cac o mau xanh
    xu ly cac truong hop giao nhau
    cac o xanh bi mat va cac o xanh them vao

    luu y: toi uu tinh tong de khong bi TLE

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int m, n, p, cnt;
int blue[N][N], red[N][N];
char c[N][N];

inline int getRed(int u, int v) {
    return red[u+p][v+p] - red[u-1][v+p] - red[u+p][v-1] + red[u-1][v-1];
}

inline int getBlue(int u, int v) {
    return blue[u+p][v+p] - blue[u-1][v+p] - blue[u+p][v-1] + blue[u-1][v-1];
}

int getInterRed(int u, int v, int x, int y) {
    int xx = max(u, x);
    int yy = max(v, y);
    int uu = min(u+p, x+p);
    int vv = min(v+p, y+p);
    if (xx <= uu && yy <= vv) return red[uu][vv] - red[xx-1][vv] - red[uu][yy-1] + red[xx-1][yy-1];
    return 0;
}

int getInterBlue(int u, int v, int x, int y) {
    int xx = max(u, x);
    int yy = max(v, y);
    int uu = min(u+p, x+p);
    int vv = min(v+p, y+p);
    if (xx <= uu && yy <= vv) return blue[uu][vv] - blue[xx-1][vv] - blue[uu][yy-1] + blue[xx-1][yy-1];
    return 0;
}

inline int calc(int u, int v, int x, int y) {
    return
        cnt + getRed(u, v) + getRed(x, y) - 2*getInterRed(u, v, x, y)
        - getBlue(u, v) - getBlue(x, y) + 2*getInterBlue(u, v, x, y);
}

void solve(void) {
    cin >> m >> n >> p; p--;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> c[i][j];
        cnt += c[i][j] == '1';
        red[i][j] = (c[i][j] == '2') + red[i-1][j] + red[i][j-1] - red[i-1][j-1];
        blue[i][j] = (c[i][j] == '1') + blue[i-1][j] + blue[i][j-1] - blue[i-1][j-1];
    }

    for (int i = 1; i+p <= m; i++, cout << '\n') for (int j = 1; j+p <= n; j++) {
        int res = 1e9;
        for (int x = 1; x+p <= m; x++) for (int y = 1; y+p <= n; y++) {
            res = min(res, calc(i, j, x, y));
        }
        cout << res << ' ';
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
