#include <bits/stdc++.h>
using namespace std;
#define task ""
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int INF = 1e9 + 7;
const int MAX = 100010;
int n, m;
int f[MAX][2];
int used[MAX][2];
vector<int> adj[MAX][2];

void dfs(int u, int prevColor) {
    if (used[u][prevColor] == 0) {
        used[u][prevColor] = 1;
        for (int v: adj[u][prevColor ^ 1]) {
            if (used[v][prevColor ^ 1] == 1) f[u][prevColor] = INF;
            if (used[v][prevColor ^ 1] == 0) dfs(v, prevColor ^ 1);
            f[u][prevColor] = max(f[u][prevColor], f[v][prevColor ^ 1] + 1);
        }
        used[u][prevColor] = 2;
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r",  stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, t; cin >> u >> v >> t;
        adj[u][t - 1].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, 0);
        dfs(i, 1);
        int cur = max(f[i][0], f[i][1]);
        cout << (cur >= INF ? -1 : cur) << '\n';
    }

	return 0;
}
