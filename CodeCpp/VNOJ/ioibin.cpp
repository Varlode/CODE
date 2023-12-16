/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

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

    bool isConnect(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return true;
        return false;
    }
} dsu;

void solve() {
    int p; cin >> p;
    dsu.build();
    for (int i = 1; i <= p; i++) {
        int x, y, z; cin >> x >> y >> z;
        if (z == 1) dsu.join(x, y);
        else cout << dsu.isConnect(x, y) << '\n';
    }
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
