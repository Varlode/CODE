/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    dung prefix cho
        hang tu trai -> phai, tu phai -> trai
        cot tu tren -> duoi, tu duoi -> tren
        duong cheo chinh 2 ben
        duong cheo phu 2 ben
    moi o thi = tong 8 prefix tren - 7

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int m, n;
char c[N][N];
int row[2][N][N], col[2][N][N], diag[4][N][N];

void solve(void) {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        cin >> c[i][j];

    /* tinh tu trai -> phai, tu tren -> duoi
        row[0], col[0], diag[0], diag[3]
    */
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        if (c[i][j] == '#') {
            row[0][i][j] = 0;
            col[0][i][j] = 0;
            diag[0][i][j] = 0;
            diag[3][i][j] = 0;
        }
        else {
            row[0][i][j] = row[0][i][j-1] + 1;
            col[0][i][j] = col[0][i-1][j] + 1;
            diag[0][i][j] = diag[0][i-1][j-1] + 1;
            diag[3][i][j] = diag[3][i-1][j+1] + 1;
        }
    }

    /* tu duoi -> tren, tu phai -> trai
        row[1], col[1], diag[1], diag[2]
    */
    for (int i = m; i >= 1; i--) for (int j = n; j >= 1; j--) {
        if (c[i][j] == '#') {
            row[1][i][j] = 0;
            col[1][i][j] = 0;
            diag[1][i][j] = 0;
            diag[2][i][j] = 0;
        }
        else {
            row[1][i][j] = row[1][i][j+1] + 1;
            col[1][i][j] = col[1][i+1][j] + 1;
            diag[1][i][j] = diag[1][i+1][j+1] + 1;
            diag[2][i][j] = diag[2][i+1][j-1] + 1;
        }
    }

    /* check bug
        row: ok
        col:ok
        diag[0] & [1]: ok
        diag[2] & [3]: ok
    */

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == '#') {
                cout << 0 << ' ';
                continue;
            }
            cout << row[0][i][j]+row[1][i][j]
            + col[0][i][j]+col[1][i][j]
            + diag[0][i][j]+diag[1][i][j]
            + diag[2][i][j]+diag[3][i][j]
            - 7 << ' ';
        }
        cout << '\n';
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
