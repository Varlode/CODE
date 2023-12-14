#include <bits/stdc++.h>
using namespace std;
#define task "painting"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 55;
int subtask, n, s;
vector<int> adj[MAX];
int pf[MAX][MAX], dp[MAX][MAX][MAX][MAX];

int cnt(int x, int y, int u, int v) {
    return pf[u][v] - pf[x - 1][v] - pf[u][y - 1] + pf[x - 1][y - 1];
}

int cur, vs[MAX];
int trcx[MAX], trcy[MAX];

bool dfs(int u) {
    if (vs[u] == cur) return false; vs[u] = cur;
    for (int v: adj[u]) {
        if (trcy[v] == 0 || dfs(trcy[v])) {
            trcx[u] = v;
            trcy[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> subtask >> n >> s;
    for (int i = 1; i <= s; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        pf[x][y] += 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            pf[i][j] += pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
    }
    if (subtask == 1) {
        int ans = 0;
        for (cur = 1; cur <= n; ++cur) {
            ans += dfs(cur);
        }
        cout << ans;
    } else {
        memset(dp, 0x3f, sizeof dp);
        for (int x = n; x >= 1; --x) for (int y = n; y >= 1; --y) {
            for (int u = x; u <= n; ++u) for (int v = y; v <= n; ++v) {
                if (cnt(x, y, u, v) == 0) {
                    dp[x][y][u][v] = 0;
                    continue;
                }
                int res = max(u - x + 1, v - y + 1);
                for (int k = x; k < u; ++k) res = min(res, dp[x][y][k][v] + dp[k + 1][y][u][v]);
                for (int k = y; k < v; ++k) res = min(res, dp[x][y][u][k] + dp[x][k + 1][u][v]);
                dp[x][y][u][v] = res;
            }
        }
        cout << dp[1][1][n][n];
    }

	return 0;
}
