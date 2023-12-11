/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
int n, m;

struct DSU {
    int lab[N], numE[N];
    void build() {
        memset(lab, -1, sizeof lab);
        memset(numE, 0, sizeof numE);
    }

    int find(int u) {
        return lab[u] < 0? u: lab[u] = find(lab[u]);
    }

    bool join(int u, int v) {
         u = find(u);
         v = find(v);
         if (u == v) {
            numE[u]++;
            return false;
         }
         if (lab[u] > lab[v]) swap(u, v);
         lab[u] += lab[v];
         numE[u] += numE[v]+1;
         lab[v] = u;
         return true;
    }
} dsu;

void solve() {
    cin >> n >> m;
    dsu.build();
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        dsu.join(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.lab[i] < 0) ans += dsu.numE[i]+dsu.lab[i]+1;
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
