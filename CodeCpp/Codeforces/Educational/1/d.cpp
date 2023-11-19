#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, k, numComp;
char a[N][N];
int comp[N][N], sz[N*N/2];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int u, int v) {
    comp[u][v] = numComp;
    for (int i = 0; i < 4; i++) {
        int x = u+dx[i], y = v+dy[i];
        if (a[x][y] == '*') sz[numComp]++;
        if (comp[x][y] || a[x][y] == '*') continue;
        dfs(x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        if (!comp[i][j] && a[i][j] == '.') {
            numComp++; 
            dfs(i, j);
        };
    }
    while (k--) {
        int x, y; cin >> x >> y;
        cout << sz[comp[x][y]] << '\n';
    }
}