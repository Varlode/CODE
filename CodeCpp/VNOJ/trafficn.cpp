/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define i2 pair<int, int>

const int N = 1e4+10;
int n, m, k, s, t;
int d[N][2];
vector< i2 > adj[N][2];

void reset() {
    for (int i = 0; i < N; i++) {
        adj[i][0].clear();
        adj[i][1].clear();
    }
    memset(d, 0x3f, sizeof d);
}

void dijkstra(int i, int u) {
    priority_queue< i2, vector< i2 >, greater< i2 > > pq;
    d[u][i] = 0;
    pq.push({0, u});

    while(pq.size()) {
        int u = pq.top().se; pq.pop();
        for (i2 &p : adj[u][i]) {
            int v = p.fi, w = p.se;
            if (d[u][i]+w < d[v][i]) {
                d[v][i] = d[u][i]+w;
                pq.push({d[v][i], v});
            }
        }
    }
}


void solve() {
    reset();
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][0].push_back({v, w});
        adj[v][1].push_back({u, w});
    }
    dijkstra(0, s);
    dijkstra(1, t);

    long long ans = d[t][0];
    for (int i = 1; i <= k; i++) {
        int u, v, w; cin >> u >> v >> w;
        ans = min({ans, (long long) d[u][0]+w+d[v][1], (long long) d[v][0]+w+d[u][1]});
    }
    if (ans == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
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
