#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+9, int maxM=1e6+9;
int n, m, q;
vector<int> adj[maxN], val[maxN];
priority_queue<
    pair<int, int>
> pq1, pq2;

struct edges {
    int u, v, w, c;
} e[maxM];

struct DSU {
    int par[maxN], sz[maxN];

    void init() {
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = i;
        }
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v  = find(v);
        if (u == v) return false;
        if (sz[u] >= sz[v]) {
            par[v] = u;
            sz[u] += sz[v];
        }
        else {
            par[u] = v;
            sz[v] += sz[u];
        }
        return true;
    }
} dsu;

void kruskal() {

}

int main() {
    dsu.init();
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    for (int i = 1; i <= q; i++) {
        int k, s; cin >> k >> s;
        int t[s], c[s];
        // init
        for (int j = 0; j < s; i++) {
            cin >> t[j] >> c[j];
            e[t[j]].c = c[j];
        }

        kruskal();

        // end
        for (int j = 0; j < s; i++) {
            e[t[j]] = 0;
        }
    }
}
