#include <bits/stdc++.h>
using namespace std;
#define task ""
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int n, m, k;
string A, B;
int cnt[10010];
int d[404][404];
int p[404][404];
vector<int> adj[404];
vector<int> comp[404];
pair<int, int> edges[10010];

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

void addEdge(int s, int t) {
    while (t != s) {
        int id = p[s][t]; ++cnt[id];
        t = t ^ edges[id].first ^ edges[id].second;
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> m >> k;
    cin >> A >> B; DSU dsu(n + m);
    for (int i = 1; i <= k; ++i) {
        int x, y; cin >> x >> y; y += n;
        edges[i] = make_pair(x, y);
        dsu.union_set(x, y);
        adj[x].push_back(i);
        adj[y].push_back(i);
    }
    for (int i = 1; i <= n + m; ++i) {
        int u = dsu.find_set(i);
        comp[u].push_back(i);
    }
    for (int i = 1; i <= n + m; ++i) {
        memset(d[i], -1, sizeof d[i]);
        queue<int> q;
        d[i][i] = 0;
        q.push(i);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int id: adj[u]) {
                int v = u ^ edges[id].first ^ edges[id].second;
                if (d[i][v] == -1) {
                    d[i][v] = d[i][u] + 1;
                    p[i][v] = id;
                    q.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n + m; ++i) if (comp[i].size()) {
        vector<int> pos;
        for (int j: comp[i]) {
            if (A[j - 1] != B[j - 1])
                pos.push_back(j);
        }
        if (pos.size() & 1) {
            cout << -1;
            return 0;
        }
        for (int j = 0; j < pos.size(); j += 2) {
            addEdge(pos[j], pos[j + 1]);
        }
    }
    vector<int> res;
    for (int i = 1; i <= k; ++i) {
        if (cnt[i] & 1)
            res.push_back(i);
    }
    cout << res.size() << '\n';
    for (int &id: res) cout << id << ' ';

	return 0;
}
