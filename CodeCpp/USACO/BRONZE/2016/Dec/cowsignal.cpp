#include <bits/stdc++.h>
using namespace std;

const int N  = 101;
char a[N][N];
int b[N*10][N*10];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "cowsignal"
    if (fopen(TASK".in", "r")) {
        freopen(TASK".in", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) 
        cin >> a[i][j];
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        if (a[i][j] == 'X') {
            b[i*k-(k-1)][j*k-(k-1)] += 1;
            b[i*k+1][j*k-(k-1)] -= 1;
            b[i*k-(k-1)][j*k+1] -= 1;
            b[i*k+1][j*k+1] += 1;
        }
    }
    for (int i = 1; i <= k*m; i++, cout << endl) for (int j = 1; j <= k*n; j++) {
        b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        if (b[i][j]) cout << 'X';
        else cout << '.';
    }
}
