/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, q;

struct SEQMENT {
    long long st[N*4];

    void upd(int i, int l, int r, int u, int v) {
        if (u < l || r < u) return;
        if (l == r) {
            st[i] = v;
            return;
        }
        int m = (l+r) >> 1;

        upd(i*2, l, m, u, v);
        upd(i*2+1, m+1, r, u, v);
        st[i] = st[i*2] + st[i*2+1];
    }

    long long get(int i, int l, int r, int u, int v) {
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) return st[i];
        int m = (l+r) >>  1;

        return get(i*2, l, m, u, v) + get(i*2+1, m+1, r, u, v);
    }
} myTree;

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int p, x, y; cin >> p >> x >> y;
        if (p == 1) myTree.upd(1, 1, n, x, y);
        else cout << myTree.get(1, 1, n, x, y) << '\n';
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
