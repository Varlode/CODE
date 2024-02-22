/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    bfs tu ngua den moi diem, sau do di chuyen tot
    nx 1: duong di ngan nhat ko mat tinh chan le

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 5001;
int t, d[N][N];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

inline bool inside(int x, int y) {
    return 0 <= x && x <= 2021 && 0 <= y && y <= 2021;
}

void bfs(int u, int v) {
    queue< ii > q;
    if (t == 1) q.push(ii(u, v));
    else {
        for (int i = 0; i < 8; i++) {
            int x = u+dx[i], y = v+dy[i];
            if (inside(x, y)) {
                d[x][y] = 1;
                q.push(ii(x, y));
            }
        }
    }
    while (q.size()) {
        u = q.front().fi; v = q.front().se; q.pop();
        for (int i = 0; i < 8; i++) {
            int x = u+dx[i]+1, y = v+dy[i];
            if (inside(x, y) && d[x][y] == 0) {
                d[x][y] = d[u][v]+1;
                q.push(ii(x, y));
            }
        }
    }
}

void solve(void) {
    int u, v, x, y;
    cin >> u >> v >> x >> y >> t;
    u += 1010; v += 1010; x += 1010; y += 1010;
    bfs(u, v);
    if (d[x][y]) cout << "YES\n" << d[x][y] << '\n';
    else cout << "NO";
}

int main(void) {
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
