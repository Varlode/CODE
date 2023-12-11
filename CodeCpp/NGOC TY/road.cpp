#include<bits/stdc++.h>
using namespace std;

struct edge {
    int v, l, c; //vertex, length, cost
    edge(int v, int l, int c): v(v), l(l), c(c) {}
    bool operator < (const edge &a) const {
        return l > a.l;
    }
};
const int N = 110, K = 110, INF = 1e9;
int d[N][K], n, k, m;
vector<vector<edge> > g;

void dijkstra() {
    priority_queue<edge> q;
    memset(d, 0x3f, sizeof d);
    d[0][k] = 0;
    q.push(edge(0, 0, k));
    while(!q.empty()) {
        int u = q.top().v, dumo = q.top().l, mo = q.top().c; q.pop();
        if(dumo > d[u][mo]) continue;
        if(u == n-1) {
            cout << dumo << '\n';
            return;
        }
        for (edge it: g[u]) {
            int v = it.v, w = it.l, c = it.c;
            if(mo >= c && d[v][mo - c] > dumo + w)
                q.push(edge(v, d[v][mo - c] = dumo + w, mo - c));
        }
    }
    cout << "-1\n";
}

void solve() {
    cin >> k >> n >> m;
    g.assign(n, vector<edge>());
    for(int i = 0; i < m; ++i) {
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        g[--u].push_back(edge(--v, l, c));
    }
    dijkstra();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "road"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
