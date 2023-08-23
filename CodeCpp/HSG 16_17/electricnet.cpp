#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+9;
int n, m, a[maxN], b[maxN], p[maxN], ans = 0;
vector<int> out;
vector<pair<int, int> > adj[maxN];
priority_queue<
    pair<pair<int, int>, pair<int, int> >
> pq;

struct DSU {
    int par[maxN];
    void init() {
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
    }
    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

int bfs(int u, int v) {
    int ret = 1e9;
    priority_queue<pair<int, pair<int, int> > > q;
    q.push({int(1e5), {0, u}});
    while(q.size()) {
        int pre = q.top().second.first, tmp = q.top().second.second; 
        ret = min(ret, q.top().first);
        q.pop();
        if (tmp == v) {
            return ret;
        }
        for (int i = 0; i < adj[tmp].size(); i++) {
            if (adj[tmp][i].first == pre) continue;
            q.push({adj[tmp][i].second, {tmp, adj[tmp][i].first}});
        }
    }
    return 0;
}

int main() {
    // freopen("electricnet.inp", "r", stdin);
    // freopen("electricnet.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> p[i];
        pq.push({{p[i], i}, {a[i], b[i]}});
    }
    dsu.init();
    while (pq.size()) {
        pair<pair<int, int>, pair<int, int> > tmp = pq.top(); pq.pop();
        if (!dsu.join(tmp.second.first, tmp.second.second)) {
            out.push_back(tmp.first.second);
            continue;
        }
        adj[tmp.second.first].push_back({tmp.second.second, tmp.first.first});
        adj[tmp.second.second].push_back({tmp.second.first, tmp.first.first});
    }
    for (int i = 0; i < out.size(); i++) {
        int tmp = bfs(a[out[i]], b[out[i]]);
        if (tmp > p[out[i]]) ans += tmp-p[out[i]];
    }
    cout << ans;
}