#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ppi pair<int, pii>
#define se second
#define fi first 

const int N = 1e6;
int n, m;
int d[N], mn[N], vstd[N], trace[N];
vector<pii> adj[N];
priority_queue<ppi> pq;

void dijsktra(int u) {
    for (auto [v, w]: adj[u]) if (!trace[v] && w+d[u] < d[v]) {
        pq.push({w+d[u], {u, v}});
    }

    while (pq.size() && trace[pq.top().se.se]) pq.pop();
    if (pq.size() == 0) return;
    auto [w, e] = pq.top(); pq.pop();
    trace[e.se] = e.fi;
    d[e.se] = w;
    dijsktra(e.se);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijsktra(1);
    int v = n; while (trace[v] != 0) vstd[v] = 1; vstd[1] = 1;
    
}