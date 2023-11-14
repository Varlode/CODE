#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ipi pair<int, ii>
#define fi first
#define se second

const int N = 1010;

int m, n, u, v;
int a[N][N], vis[N][N], d[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

priority_queue<ipi, vector<ipi>, greater<ipi> > pq;

bool check(int x, int y) {
    return (1 <= x && x <= m && 1 <= y && y <= n && a[x][y] >= 0);
}

bool dijkstra(int x, int y) {
    pq.push({1, {x, y}});
    while (pq.size()) {
        auto [val, p] = pq.top(); pq.pop();
        x = p.first; y = p.second;
        vis[x][y] = true;
        d[x][y] = val;
        if (x == u && y == v)
            return true;
        for (int i = 0; i < 4; i++) {
            if (vis[x+dx[i]][y+dy[i]] == 0 && (check(x+dx[i], y+dy[i]))) 
                pq.push({1 + val, {x+dx[i], y+dy[i]}});
        }
        while (pq.size() && vis[pq.top().se.fi][pq.top().se.se]) pq.pop();
        if (pq.empty()) return false;
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
    cin >> m >> n >> y >> x >> v >> u;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
    }
    if (dijkstra(x, y)) cout << d[u][v];
    else cout << -1;
}