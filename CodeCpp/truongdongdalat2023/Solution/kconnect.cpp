#include <bits/stdc++.h>
using namespace std;
#define task "kconnect"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 300030;
int n, m, k;
int lab[MAX];
bool res[MAX];
bool special[MAX];
vector<int> adj[MAX];
pair<int, int> edges[MAX];

int find_set(int v) {
    return lab[v] < 0 ? v : lab[v] = find_set(lab[v]);
}

bool union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return false;
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v]; lab[v] = u;
    return true;
}

bool dfs(int u, int p) {
    bool ok = special[u];
    for (int id: adj[u]) {
        int v = u ^ edges[id].first ^ edges[id].second;
        if (v != p) {
            if (dfs(v, u)) {
                res[id] = true;
                ok = true;
            }
        }
    }
    return ok;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> m >> k;
    memset(lab, -1, sizeof lab);
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        edges[i] = make_pair(u, v);
        if (union_set(u, v) == true) {
            adj[u].push_back(i);
            adj[v].push_back(i);
        }
    }
    int u;
    for (int i = 1; i <= k; ++i) {
        cin >> u;
        special[u] = true;
    }
    dfs(u, -1);
    for (int i = 1; i <= m; ++i) {
        cout << res[i] << ' ';
    }

	return 0;
}
