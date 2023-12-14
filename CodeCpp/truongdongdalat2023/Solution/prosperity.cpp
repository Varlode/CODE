#include <bits/stdc++.h>
using namespace std;
#define task "prosperity"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 300030;
int n, q;
int timer;
int p[MAX];
int par[MAX];
int pos[MAX];
int dist[MAX];
int L[MAX], R[MAX];
vector<int> adj[MAX];
long long bit1[MAX], bit2[MAX];

void update(long long bit[], int id, long long delta) {
    for (; id <= n; id += id & -id)
        bit[id] += delta;
}

long long get(long long bit[], int id) {
    long long res = 0;
    for (; id > 0; id -= id & -id)
        res += bit[id];
    return res;
}

void update(int l, int r, int delta) {
    update(bit1, l, +delta);
    update(bit1, r + 1, -delta);
    update(bit2, l, +1LL * l * delta);
    update(bit2, r + 1, -1LL * (r + 1) * delta);
}

long long get(int id) {
    return 1LL * (id + 1) * get(bit1, id) - get(bit2, id);
}

long long get(int l, int r) {
    return get(r) - get(l - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    {
        memset(dist, -1, sizeof dist);
        memset(L, 0x3f, sizeof L);
        memset(R, 0, sizeof R);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (q.size()) {
            int u = q.front(); q.pop(); pos[u] = ++timer;
            for (int v: adj[u]) if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
        for (int u = 1; u <= n; ++u) {
            for (int v: adj[u]) if (dist[u] == dist[v] - 1) {
                L[u] = min(L[u], pos[v]);
                R[u] = max(R[u], pos[v]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) update(pos[i], pos[i], p[i]);
    while (q--) {
        int type, u; cin >> type >> u;
        if (type == 1) {
            int x; cin >> x; if (L[u] <= R[u]) update(L[u], R[u], x);
            if (par[u] > 0) update(pos[par[u]], pos[par[u]], x);
            update(pos[u], pos[u], 2 * x);
        } else {
            long long res = 0; if (L[u] <= R[u]) res += get(L[u], R[u]);
            if (par[u] > 0) res += get(pos[par[u]], pos[par[u]]);
            res += get(pos[u], pos[u]);
            cout << res << '\n';
        }
    }

	return 0;
}
