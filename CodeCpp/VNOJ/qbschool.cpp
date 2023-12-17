/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 5001;
int n, m;
long long d[2][N];
vector< ii > adj[N];

void dijkstra(int u) {
    priority_queue< ii, vector< ii >, greater< ii > > pq;
    memset(d[0], 0x3f, sizeof d[0]);
    d[0][u] = 0; d[1][u] = 1;

    pq.push({0, u});
    while (pq.size()) {
        int wu = pq.top().fi; u = pq.top().se; pq.pop();
        if (wu > d[0][u]) continue;
        for (ii &p: adj[u]) {
            int v = p.first, w = p.second;
            if (d[0][u] + w == d[0][v]) d[1][v] += d[1][u];
            if (d[0][u] + w < d[0][v]) {
                d[0][v] = d[0][u]+w;
                d[1][v] = d[1][u];
                pq.push({d[0][v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k, u, v, w;
        cin >> k >> u >> v >> w;
        adj[u].push_back({v, w});
        if (k == 2) adj[v].push_back({u, w});
    }
    dijkstra(1);
    cout << d[0][n] << ' ' << d[1][n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
