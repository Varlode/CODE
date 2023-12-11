/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 201;

int n, m, p, q, s, t;
int a[N][N];

inline bool inside(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void bfs(int x, int y) {
    queue< pair<int, int> > q;

    q.push({x, y});
    a[x][y] = 0;

    while (q.size()) {
        x = q.front().fi; y = q.front().se; q.pop();

        // di len phai
        for (int i = 1; i <= n; i++) {
            int xx = x-i, yy = y+i;
            if (!inside(xx, yy) || a[x][y]+1 > a[xx][yy]) break;
            a[xx][yy] = a[x][y]+1;
            q.push({xx, yy});
        }

        // di xuong phai
        for (int i = 1; i <= n; i++) {
            int xx = x+i, yy = y+i;
            if (!inside(xx, yy) || a[x][y]+1 > a[xx][yy]) break;
            a[xx][yy] = a[x][y]+1;
            q.push({xx, yy});
        }

        // di xuong trai
        for (int i = 1; i <= n; i++) {
            int xx = x+i, yy = y-i;
            if (!inside(xx, yy) || a[x][y]+1 > a[xx][yy]) break;
            a[xx][yy] = a[x][y]+1;
            q.push({xx, yy});
        }

        // di len trai
        for (int i = 1; i <= n; i++) {
            int xx = x-i, yy = y-i;
            if (!inside(xx, yy) || a[x][y]+1 > a[xx][yy]) break;
            a[xx][yy] = a[x][y]+1;
            q.push({xx, yy});
        }
    }
}

void solve() {
    cin >> n >> m >> p >> q >> s >> t;
    memset(a, 0x3f, sizeof a);
    for (int i = 1; i <= m; i++) {
        int r, c; cin >> r >> c;
        a[r][c] = -1;
    }
    bfs(p, q);
    if (a[s][t] == 0x3f3f3f3f) cout << -1;
    else cout << a[s][t] << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
