/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010101;
int n, m, d[N];
vector<pair<int, int> > adj[N];

void dijkstra(int u) {
    #define klasdfh pair<int, int>
    priority_queue<klasdfh, vector<klasdfh>, greater<klasdfh> > minHeap;

    memset(d, 0x3f, sizeof d);
    minHeap.push({0, u});
    d[u] = 0;

    while (minHeap.size()) {
        u = minHeap.top().second; minHeap.pop();
        for (auto &p: adj[u]) {
            int v = p.first, w = p.second;
            if (v == u || d[u]+w >= d[v]) continue;
            d[v] = d[u]+w;
            minHeap.push({d[v], v});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1);
    cout << d[n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "duongdi"
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
