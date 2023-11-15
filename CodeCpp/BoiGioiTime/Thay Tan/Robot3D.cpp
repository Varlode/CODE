#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

const int N = 1010;
int a, m, n, k;
int cam[N][N], o[N][N], vis[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int getSum(int x, int y, int u, int v) {
    return cam[u][v] - cam[u][y-1] - cam[x-1][v] + cam[x-1][y-1];
}

int checkCam(int x, int y, int u, int v) {
    return (1 <= x && u <= m && 1 <= y && v <= n && getSum(x, y, u, v) == 0);
}

void bfs() {
    queue<ii> q;
    q.push({1, 1});
    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        if (checkCam(x, y, x+a-1, y+a-1)) {
            o[x][y] += 1;
            o[x+a][y+a] += 1;
            o[x][y+a] -= 1;
            o[x+a][y] -= 1;   
            for (int i = 0; i < 4; i++) 
                if (vis[x+dx[i]][y+dy[i]] == 0) q.push({x+dx[i], y+dy[i]});
        }
    }
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
    bfs();
    int ans = 0;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        o[i][j] += o[i-1][j] + o[i][j-1] - o[i-1][j-1];
        if (o[i][j] > 0) ans++;
    }
    cout << ans;
}