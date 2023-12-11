/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 101010, M = 1010101;
int n, m, q, t[101];

struct edge {
    int u, v, w, n;
};
edge e[M];

struct DSU {
    int lab[N];
    void build() {
        for (int u = 1; u <= n; u++) lab[u] = -1;
    }

    int find(int u) {
        return lab[u] < 0? u: lab[u] = find(lab[u]);
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (lab[u] > lab[v]) swap(u, v);
            lab[u] += lab[v];
            lab[v] = u;
            return true;
        }
        return false;
    }
} dsu;

void query() {
    dsu.build();
    int k, s; cin >> k >> s;
    for (int j = 1; j <= s; j++) {
        int c; cin >> t[j] >> c;
        e[t[j]].n = c;
        swap(e[t[j]].n, e[t[j]].w);
    }
    for (int j = 1; j <= m; j++) {
        if (e[j].w < e[k].w) dsu.join(e[j].u, e[j].v);
    }

    if (dsu.join(e[k].u, e[k].v)) cout << "NO\n";
    else cout << "YES\n";

    for (int j = 1; j <= s; j++) {
        swap(e[t[j]].n, e[t[j]].w);
    }
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= q; i++) {
        query();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "comnet"
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
