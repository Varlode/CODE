/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define _pii pair<int, int>

const int N = 20;
ll val[N][N], check[N][N];
ll cheoChinh[N], cheoPhu[N], hang[N], cot[N], o[N][N];
ll ans;
vector<_pii> gift, frees;
int k;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

ll calc() {
    ll res = 0;
    for (_pii &p: gift) {
        int i = p.first, j = p.second;
        if (o[i][j] || cheoChinh[8-i+j] || cheoPhu[i+j-1] ||
            hang[i] || cot[j])
            res += val[i][j];
    }
    return res;
}

void queen(int x, int y) {
    hang[x]++;
    cot[y]++;
    cheoChinh[8-x+y]++;
    cheoPhu[x+y-1]++;
    ans = max(ans, calc());
    cheoChinh[8-x+y]--;
    cheoPhu[x+y-1]--;
    hang[x]--;
    cot[y]--;
}

void rook(int x, int y) {
    check[x][y] = 1;
    hang[x]++;
    cot[y]++;
    for (_pii &p: frees) {
        int i = p.first, j = p.second;
        if (check[i][j]) continue;
        queen(i, j);
    }
    hang[x]--;
    cot[y]--;
    check[x][y] = 0;
}

void bishop(int x, int y) {
    check[x][y] = 1;
    cheoChinh[8-x+y]++;
    cheoPhu[x+y-1]++;
    for (_pii &p: frees) {
        int i = p.first, j = p.second;
        if (check[i][j]) continue;
        rook(i, j);
    }
    cheoChinh[8-x+y]--;
    cheoPhu[x+y-1]--;
    check[x][y] = 0;
}

void knight(int x, int y) {
    check[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int xx = x+dx[i], yy = y+dy[i];
        if (1 <= xx && xx <= 8 && 1 <= yy && yy <= 8)
            o[xx][yy]++;
    }
    for (_pii &p: frees) {
        int i = p.first, j = p.second;
        if (check[i][j]) continue;
        bishop(i, j);
    }
    for (int i = 0; i < 8; i++) {
        int xx = x+dx[i], yy = y+dy[i];
        if (1 <= xx && xx <= 8 && 1 <= yy && yy <= 8)
            o[xx][yy]--;
    }
    check[x][y] = 0;
}

void solve() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int x, y, w; cin >> x >> y >> w;
        val[x][y] = w;
    }
    for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) {
        if (val[i][j]) gift.push_back({i, j});
        else frees.push_back({i, j});
    }
    for (_pii &p: frees) {
        int i = p.first, j = p.second;
        knight(i, j);
    }
    cout << ans;
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
