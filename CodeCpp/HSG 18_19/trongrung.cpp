#include<bits/stdc++.h>
using namespace std;

const int maxN = 109;
int m, n, x, y, ans = 0, a[maxN][maxN], vstd[maxN][maxN];
queue<pair<int, int> > q;

int c[4] = {0, 1, 0, -1}, r[4] = {1, 0, -1, 0};

void bfs(int u, int v) {
    ans++;
    vstd[u][v] = 1;
    for (int i = 0; i < 4; i++) {
        if (a[u+c[i]][v+r[i]] || vstd[u+c[i]][v+r[i]]) continue;
        q.push(make_pair(u+c[i], v+r[i]));
    }
    while (q.size() && vstd[q.front().first][q.front().second]) q.pop();
    if (q.empty()) return;
    pair<int, int> tmp = q.front(); q.pop();
    bfs(tmp.first, tmp.second);
}

int main() {
    freopen("trongrung.inp", "r", stdin);
    freopen("trongrung.out", "w", stdout);
    cin >> m >> n >> x >> y;
    for (int i = 1; i <= m; i++) a[i][0] = a[i][n+1] = 1;
    for (int i = 1; i <= n; i++) a[0][i] = a[m+1][i] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    bfs(x, y);
    cout << ans;
}