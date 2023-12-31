/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    phep xor
    dung segment tree va lazy propration

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, m;

struct SEGMENT {
    int st[N*4], lz[N*4];

    void upd(int i, int l, int r, int u, int v) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            st[i] = (r-l+1) - st[i];
            lz[i] ^= 1;
            return;
        }

        int m = (l+r) >> 1;
        upd(i*2, l, m, u, v);
        upd(i*2+1, m+1, r, u, v);
        st[i] = st[i*2]+st[i*2+1];
        if(lz[i]) st[i] = (r-l+1) - st[i];
    }

    int get(int i, int l, int r, int u, int v, int f) {
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) {
            if (f) return (r-l+1) - st[i];
            else return st[i];
        }

        int m = (l+r) >> 1;
        return get(i*2, l, m, u, v, lz[i]^f) + get(i*2+1, m+1, r, u, v, lz[i]^f);
    }
} myTree;

void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int type, l, r; cin >> type >> l >> r;
        if (!type) myTree.upd(1, 1, n, l, r);
        else cout << myTree.get(1, 1, n, l, r, 0) << '\n';
    }
}

int main(void) {
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
