/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 50500;
int n, q;

struct SEQMENT {
    long long st[N*4], lazy[N*4];

    void down(int i) {
        long long v = lazy[i];
        lazy[i*2] += v;
        st[i*2] += v;

        lazy[i*2+1] += v;
        st[i*2+1] += v;

        lazy[i] = 0;
    }

    void upd(int i, int l, int r, int u, int v, int val) {
        if (v < l || r < u) return;
        if (u <= l && r <= v) {
            st[i] += val;
            lazy[i] += val;
            return;
        }
        int m = (l+r) >> 1;

        down(i);

        upd(i*2, l, m, u, v, val);
        upd(i*2+1, m+1, r, u, v, val);
        st[i] = max(st[i*2], st[i*2+1]);
    }

    int get(int i, int l, int r, int u, int v) {
        if (r < u || v < l) return -1e9;
        if (u <= l && r <= v) return st[i];
        int m = (l+r) >>  1;

        down(i);

        return max(get(i*2, l, m, u, v), get(i*2+1, m+1, r, u, v));
    }
} myTree;

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int p; cin >> p;
        if (p == 0) {
            int x, y, k; cin >> x >> y >> k;
            myTree.upd(1, 1, n, x, y, k);
        }
        if (p == 1) {
            int x, y; cin >> x >> y;
            cout << myTree.get(1, 1, n, x, y) << '\n';
        }
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
