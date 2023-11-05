#include <bits/stdc++.h>
using namespace std;

const int N = 11, M = 101, E = (N+1)*(M+1), MOD = 111539786;
int m, n, k, s;
int dp[N][M][E], cam[N][M];

void add(int& a, int b) {
    a += b;
    if (a > MOD) a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> m >> n >> k >> s;
    for (int i = 1; i <= s; i++) {
        int x, y; cin >> x >> y;
        cam[x][y] = 1;
    }
    int V = (m+1)*(n+1);
    int Eneed = s + k + V - 1 - n - m;
    dp[0][n][Eneed] = 1;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        for (int c = Eneed; c >= 0; c--) {
            int tmp = (j == 1)? dp[i-1][n][c]: dp[i][j-1][c];
            if (c >= 2) add(dp[i][j][c-2], tmp);
            if (c && !cam[i][j]) {
                if (i != m && !cam[i+1][j]) add(dp[i][j][c-1], tmp);
                if (j != n && !cam[i][j+1]) add(dp[i][j][c-1], tmp);
            }
        }
    }
    cout << dp[m][n][0];
}