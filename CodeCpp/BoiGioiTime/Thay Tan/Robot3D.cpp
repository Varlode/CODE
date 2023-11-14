#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int a, m, n, k;
int cam[N][N], o[N][N];

int getSum(int x, int y, int u, int v) {
    return cam[u][v] - cam[u][y-1] - cam[x-1][v] + cam[x-1][y-1];
}

int checkCam(int x, int y, int u, int v) {
    return (1 <= x && u <= m && 1 <= y && v <= n && getSum(x, y, u, v) == 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "Robot3D"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> a >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        cam[x][y] = 1;
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) 
        cam[i][j] += cam[i-1][j] + cam[i][j-1] - cam[i-1][j-1];
    for (int i = 1; i <= m; i += a) for (int j = 1; j <= n; j += a) {
        if (checkCam(i, j, i+a-1, j+a-1)) {
            o[i][j] += 1;
            o[i+a][j+a] += 1;
            o[i][j+a] -= 1;
            o[i+a][j] -= 1;   
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        o[i][j] += o[i-1][j] + o[i][j-1] - o[i-1][j-1];
        if (o[i][j] > 0) ans++;
    }
    cout << ans;
}