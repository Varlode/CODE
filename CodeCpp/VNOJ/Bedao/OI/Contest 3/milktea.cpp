/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 201010;
int n, m, k;
int mark[N], goOther[N], comp[N], p[N];
ll d[N], dOther[N];
vector<pair<int, int> > adj[N];

struct EDGE {
    int u, v, w;
} edge[N];

void dijkstra(int u) {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push({0, u});

    memset(d, 0x3f, sizeof d);
    d[0] = 0;

    while (pq.size()) {
        u = pq.top().second; pq.pop();
        for (pair<int, int> &p: adj[u]) {
            int& v = p.first, w = p.second;
            if (d[u]+w < d[v]) {
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}

void trace(int u) {
    queue<pair<ll, int> > q;
    q.push({0, u});
    while (q.size()) {
        u = q.front().second; q.pop();
        for (pair<int, int> &p: adj[u]) {
            int& v = p.first, w = p.second;
            if (d[u]+w == d[v] && !comp[v]) {
                comp[v] = comp[u];
                q.push({d[v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    for (int i = 1; i <= k; i++) {
        cin >> p[i] >> goOther[p[i]];
        mark[p[i]] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int& u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (mark[u] && mark[v]) continue;
        if (mark[u] || mark[v]) {
            if (mark[u]) adj[0].push_back({v, w});
            else adj[0].push_back({u, w});
        }
        else {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    dijkstra(0);

    for (int i = 1; i <= m; i++) {
        int& u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (mark[u] && mark[v]) continue;
        if (mark[u] || mark[v]) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    for (int i = 1; i <= k; i++) {
        d[p[i]] = 0;
        comp[p[i]] = p[i];
        trace(p[i]);
    }

    memset(dOther, 0x3f, sizeof dOther);
    for (int i = 1; i <= m; i++) {
        int& u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (comp[u] == comp[v]) continue;
        dOther[comp[u]] = min(dOther[comp[u]], d[u]+d[v]+w);
        dOther[comp[v]] = min(dOther[comp[v]], d[u]+d[v]+w);
    }

    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            if (goOther[i]) cout << dOther[i] << ' ';
            else cout << 0 << ' ';
        }
        else cout << d[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "milktea"
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
