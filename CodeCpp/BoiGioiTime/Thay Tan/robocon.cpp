#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 1010;

int m, n, u, v;
int a[N][N], vis[N][N], d[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

queue<ii> q;

bool check(int x, int y) {
    return (1 <= x && x <= m && 1 <= y && y <= n && a[x][y] >= 0);
}

bool bfs(int x, int y) {
    q.push({x, y});
    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        vis[x][y] = true;
        if (x == u && y == v)
            return true;
        for (int i = 0; i < 4; i++) {
            if (vis[x+dx[i]][y+dy[i]] == 0 && (check(x+dx[i], y+dy[i]))) {
                d[x+dx[i]][y+dy[i]] = d[x][y] + 1;
                q.push({x+dx[i], y+dy[i]});
            }
        }
        while (q.size() && vis[q.front().fi][q.front().se]) q.pop();
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    int x, y;
    cin >> m >> n >> x >> y >> u >> v;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
    }
    d[x][y] = 1;
    if (bfs(x, y)) cout << d[u][v];
    else cout << -1;
}