#include <bits/stdc++.h>
using namespace std;

#define ii pair<long long, int>

const int N = 1010, M = 100010;
int n, m;
long long d[N];

vector< ii > adj[N];

int dijkstra(int root) {
    priority_queue< ii, vector< ii >, greater< ii > > pq;
    memset(d, 0x3f, sizeof d);

    for (ii &p: adj[root]) {
        d[p.first] = p.second;
        pq.push({p.second, p.first});
    }

    while (pq.size()) {
        int u = pq.top().second, ans = pq.top().first; pq.pop();
        if (u == root) return ans;
        for (ii &p: adj[u]) {
            int v = p.first, w = p.second;
            if (d[u]+w<d[v]) {
                if (v == root)
                    pq.push({d[u]+w, v});
                else
                    pq.push({d[v] = d[u]+w, v});
            }
        }
    }
    return -1;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
        cout << dijkstra(i) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "tours13"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
