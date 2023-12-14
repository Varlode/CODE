#include <bits/stdc++.h>
using namespace std;
#define task "glight"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 100010;
int n, m;
int cnt[MAX];
int deg[MAX];
int comp[MAX];
bool used[MAX];
vector<int> g[MAX];
vector<int> adj[MAX];

struct DSU {
    vector<int> lab;

    DSU(int _n = 0) {
        lab.assign(_n + 5, -1);
    }

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
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        if (c == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            dsu.union_set(u, v);
            deg[u] += 1;
            deg[v] += 1;
        }
    }
    int res = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        int j = dsu.find_set(i);
        cnt[j] += deg[i] & 1;
        ++comp[j];
        for (int x: adj[i]) {
            int y = dsu.find_set(x);
            g[j].push_back(y);
        }
    }
    for (int i = 1; i <= n; ++i) if (comp[i] > 1) {
        if (cnt[i] >= 2) {
            used[i] = true;
            q.push(i);
        }
    }
    while (q.size()) {
        int u = q.front(); q.pop(); res += cnt[u] / 2;
        for (int v: g[u]) if (!used[v]) {
            used[v] = true;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; ++i) if (comp[i] > 1) {
        if (used[i] == false) {
            used[i] = true;
            q.push(i);
            ++res;
            while (q.size()) {
                int u = q.front(); q.pop();
                for (int v: g[u]) if (!used[v]) {
                    used[v] = true;
                    q.push(v);
                }
            }
        }
    }
    cout << res;

	return 0;
}
