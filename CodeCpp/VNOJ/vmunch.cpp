/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

const int N = 101;
int n, m;
int d[N][N];
char a[N][N];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}

void bfs(int x, int y) {
    queue< ii > q;
    q.push(ii(x, y));
    d[x][y] = 1;

    while (q.size()) {
        ii p = q.front(); q.pop();
        x = p.first; y = p.second;
        for (int i = 0; i < 4; i++) {
            int xx = x+dx[i], yy = y+dy[i];
            if (inside(xx, yy) && a[xx][yy] != '*' && d[xx][yy] == 0) {
                d[xx][yy] = d[x][y]+1;
                q.push(ii(xx, yy));
            }
        }
    }
    cout << d[1][1] - 1;
}

void solve() {
    cin >> m >> n;
    int s, t;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'C') {
            s = i;
            t = j;
        }
    }
    bfs(s, t);
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
