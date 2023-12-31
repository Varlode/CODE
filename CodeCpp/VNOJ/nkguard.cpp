/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    bfs tu x, y cac o co cung gia tri
    lay max cac cua vung lien thong ke

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 702;
int m, n, a[N][N], ans;
bool vis[N][N];

void init(void) {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        cin >> a[i][j];
}

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

inline bool inside(int x, int y) {
    return !vis[x][y] && 1 <= x && x <= m && 1 <= y && y <= n;
}

void bfs(int x, int y) {
    int mx = 0, val = a[x][y];
    queue< ii > q;
    q.push(ii(x, y));

    while(q.size()) {
        x = q.front().fi, y = q.front().se; q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int i = 0; i < 8; i++) {
            int u = x+dx[i], v = y+dy[i];
            mx = max(mx, a[u][v]);
            if (inside(u, v) && a[u][v] == val)
                q.push(ii(u, v));
        }
    }
    if (val && mx <= val) ans++;
}

void solve(void) {
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        if (!vis[i][j] && a[i][j]) bfs(i, j);
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    init();
    solve();
}
