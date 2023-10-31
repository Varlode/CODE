#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ppi pair<int, pi>
#define fi first
#define se second

const int N = 100100;
int n;  

int par[N], m[N];

inline void initDSU() {
    for (int i = 1; i <= n; i++) par[i] = i;
}

int find(int u) {
    return par[u] == u? u: par[u] = find(par[u]);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("paradigm.inp", "r", stdin);
    freopen("paradigm.out", "w", stdout);
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> m[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        pq.push({max(m[u], m[v]), {u, v}});
    }
    initDSU();
    long long ans = 0;
    while (pq.size()) {
        auto u = pq.top(); pq.pop();
        int find_u = find(u.se.fi), find_v = find(u.se.se);
        if (find_u != find_v) {
            int max_u = m[find_u];
            int max_v = m[find_v];
            ans += max_u + max_v;
            par[find_v] = find_u;
            m[find_u] = max(max_u, max_v);
        }
    }
    cout << ans;    
}