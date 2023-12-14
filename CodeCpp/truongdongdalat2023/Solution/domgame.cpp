#include <bits/stdc++.h>
using namespace std;
#define task "domgame"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int dx[] = {-1, 0, 0, +1};
const int dy[] = {0, -1, +1, 0};
int cur;
int nRow, nCol;
vector<int> vs;
vector<int> trcx;
vector<int> trcy;
vector<bool> vis[2];
int cntB = 0, cntW = 0;
vector<vector<char>> a;
vector<vector<int>> id;
vector<vector<int>> adj;
vector<vector<int>> rev;

bool dfs(int u) {
    if (vs[u] == cur) return false;
    vs[u] = cur;
    for (int v: adj[u]) {
        if (trcy[v] == 0 || dfs(trcy[v])) {
            trcx[u] = v;
            trcy[v] = u;
            return true;
        }
    }
    return false;
}

int bfs(int u) {
    for (int i = 0; i < 2; ++i) vis[i].assign(cntW + 5, 0);
    queue<pair<int, int>> q;
    q.emplace(u, 0);
    while (q.size()) {
        int u = q.front().first, t = q.front().second; q.pop();
        if (t == 0) {
            int v = trcx[u]; if (vis[1][v] == false) {
                vis[1][v] = true;
                q.emplace(v, 1);
            }
        } else {
            for (int v: rev[u]) if (vis[0][v] == false) {
                vis[0][v] = true;
                q.emplace(v, 0);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= cntW; ++i) {
        res += vis[1][i];
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> nRow >> nCol;
    a.resize(nRow + 05);
    id.resize(nRow + 5);
    for (int i = 1; i <= nRow; ++i) {
        a[i].resize(nCol + 05);
        id[i].resize(nCol + 5);
        for (int j = 1; j <= nCol; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') continue;
            if (i % 2 == j % 2) id[i][j] = ++cntB; else id[i][j] = ++cntW;
        }
    }
    if (cntB != cntW) {
        assert(false);
    }
    vs.resize(cntB + 5);
    adj.resize(cntB + 5);
    rev.resize(cntB + 5);
    trcx.resize(cntB + 5);
    trcy.resize(cntB + 5);
    for (int i = 1; i <= nRow; ++i) {
        for (int j = 1; j <= nCol; ++j) {
            if (a[i][j] == '#' || (i % 2 != j % 2)) continue;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 1 || x > nRow) continue;
                if (y < 1 || y > nCol) continue;
                if (a[x][y] == '#') continue;
                adj[id[i][j]].push_back(id[x][y]);
                rev[id[x][y]].push_back(id[i][j]);
            }
        }
    }
    int cnt = 0;
    for (cur = 1; cur <= cntB; ++cur) {
        cnt += dfs(cur);
    }
    if (cnt != cntB) {
        assert(false);
    }
    int ans = cntB * (cntB - 1);
    for (int i = 1; i <= cntB; ++i) {
        ans += cntW - bfs(i);
    }
    cout << min(ans, 1000000);

	return 0;
}
