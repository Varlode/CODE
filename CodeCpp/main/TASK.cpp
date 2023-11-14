#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ppi pair<pi, pi>
const int N = 1010;
int d[3], m, n, k;
int o[N][N], dp[N][N];
int vis[N][N][3][3];
queue<ppi> q;

bool checkCam(int x, int y, int u, int v) {
    return (o[x][y] - o[x-1][v] - o[u][y-1] + o[x-1][v-1] == 0);
}

void bfs() {
    q.push({{1, 1}, {0, 1}});
    while (q.size()) {
        auto [p1, p2] = q.front(); q.pop();
        auto [x, y] = p1;
        auto [d1, d2] = p2;
        if (vis[x][y][d1][d2]) continue;
        vis[x][y][d1][d2] = 1;
        // lat phai
        if ()
        // lat trai
        
        // lat len
        
        // lat phai
        
        // sang phai

        // sang trai

        // len 

        // xuong

    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> d[0] >> d[1] >> d[2] >> m >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        o[x][y] = 1;
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) 
        o[i][j] += o[i][j-1] + o[i-1][j] - o[i-1][j-1];
    bfs();
}