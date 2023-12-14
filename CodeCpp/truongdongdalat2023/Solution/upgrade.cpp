#include <bits/stdc++.h>
using namespace std;
#define task "upgrade"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 200020;
int n, m;
int timer;
int st[MAX << 2];
int lz[MAX << 2];
vector<int> adj[MAX];
int tin[MAX], tout[MAX];

void dfs(int u, int p) {
    tin[u] = ++timer;
    for (int v: adj[u]) if (v != p) {
        dfs(v, u);
    }
    tout[u] =  timer;
    sort(all(adj[u]), [](const int &u, const int &v) {
        return tin[u] < tin[v];
    });
}

bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

struct event {
    int y, a, b, delta;

    event(int _y = 0, int _a = 0, int _b = 0, int _delta = 0) {
        y = _y;
        a = _a;
        b = _b;
        delta = _delta;
    }

    bool operator< (const event &other) const {
        if (y != other.y) return y < other.y;
        return delta < other.delta;
    }
};
vector<event> events;

void push(int id) {
    if (lz[id] != 0) {
        st[id << 1] += lz[id]; st[id << 1 | 1] += lz[id];
        lz[id << 1] += lz[id]; lz[id << 1 | 1] += lz[id];
        lz[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, int delta) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        st[id] += delta;
        lz[id] += delta;
        return;
    }
    int mid = l + r >> 1; push(id);
    update(id << 1, l, mid, u, v, delta);
    update(id << 1 | 1, mid + 1, r, u, v, delta);
    st[id] =   max(st[id << 1], st[id << 1 | 1]);
}
#define update(l, r, delta) update(1, 1, n, l, r, delta)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        if (tin[u] > tin[v]) swap(u, v);
        if (ancestor(u, v) == true) {
            int l = 0, r = adj[u].size();
            while (r - l > 1) {
                int mid = l + r >> 1;
                if (tin[adj[u][mid]] <= tin[v]) l = mid; else r = mid;
            }
            int node = adj[u][l];
            if (tin[node] > 1) {
                int c = tin[v], d = tout[v];
                int a = 1, b = tin[node] - 1;
                if (b > d) swap(a, c), swap(b, d);
                events.emplace_back(c + 0, a, b, +w);
                events.emplace_back(d + 1, a, b, -w);
            }
            if (tout[node] < n) {
                int c = tin[v], d = tout[v];
                int a = tout[node] + 1, b = n;
                if (b > d) swap(a, c), swap(b, d);
                events.emplace_back(c + 0, a, b, +w);
                events.emplace_back(d + 1, a, b, -w);
            }
        } else {
            int a = tin[u], b = tout[u];
            int c = tin[v], d = tout[v];
            if (b > d) swap(a, c), swap(b, d);
            events.emplace_back(c + 0, a, b, +w);
            events.emplace_back(d + 1, a, b, -w);
        }
    }
    int res = 0;
    sort(all(events));
    for (event &tmp: events) {
        int y = tmp.y, a = tmp.a, b = tmp.b, delta = tmp.delta;
        update(a, b, delta); res = max(res, st[1]);
    }
    cout << res;

	return 0;
}
