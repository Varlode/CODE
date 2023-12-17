/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
int n, m;

struct EDGE {
    int u, v, w;
} e[N];

struct DSU {
    int lab[N];

    void build() {
        memset(lab, -1, sizeof lab);
    }

    int find(int u) {
        return lab[u] < 0? u: lab[u] = find(lab[u]);
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }
} dsu;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[i].u = u; e[i].v = v; e[i].w = w;
    }
    sort(e+1, e+1+m, [] (EDGE a, EDGE b) {
        return a.w < b.w;
    });
    int ans = 0;
    dsu.build();
    for (int i = 1; i <= m; i++) {
        if (dsu.join(e[i].u, e[i].v)) ans = e[i].w;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
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
