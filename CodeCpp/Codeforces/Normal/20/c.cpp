#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll, ll>
#define iii pair<ll, ii>

#define fi first
#define se second

const int N = 1e6;
int n, m;
int trace[N];
ll d[N];

vector<int> ans;
vector<ii> adj[N];
priority_queue<iii, vector<iii>, greater<iii> > pq;

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

void TRACE(int u) {
    ans.push_back(u);
    if (trace[u] != 0) TRACE(trace[u]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        d[i] = 1e18;
        trace[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    d[1] = 0;
    dijsktra(1);
    TRACE(n);
    if (ans.back() != 1) {
        cout << -1;
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for (int i: ans) {
        cout << i << ' ';
    }
}