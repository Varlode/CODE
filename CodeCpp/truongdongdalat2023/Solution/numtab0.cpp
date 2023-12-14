#include <bits/stdc++.h>
using namespace std;
#define task "numtab0"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 110;
int n;
int a[MAX][MAX];
int cur, vs[MAX];
bool ok[MAX][MAX];
vector<int> adj[MAX];
int trcx[MAX], trcy[MAX];

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) adj[i].push_back(j);
        }
    }
    int cnt = 0;
    for (cur = 1; cur <= n; ++cur) {
        cnt += dfs(cur);
    }
    if (cnt != n) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        ok[i][trcx[i]] = 1;
    }
    vector<pair<int, int>> op;
    for (int cur = 1; cur <= n; ++cur) {
        for (int i = cur + 1; i <= n + 0; ++i) {
            if (ok[i][cur] == true) {
                op.emplace_back(cur, i);
                for (int j = 1; j <= n; ++j) {
                    swap(ok[cur][j], ok[i][j]);
                }
            }
        }
    }
    cout << op.size() << '\n';
    for (pair<int, int> &tmp: op) cout << "1 " << tmp.first << ' ' << tmp.second << '\n';
	return 0;
}
