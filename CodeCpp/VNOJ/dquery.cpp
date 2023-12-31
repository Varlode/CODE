/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    chuyen truy van ve offline tuc dung Sweepline de giai
    trick: sort truy van theo r, vi duoi l se khong bi anh huong

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 3e4+1, Q = 2e5+1, LIM = 1e6+1;
int n, q, pre[LIM], ans[Q];

struct QUERY {
    int l, r, val, type;
    QUERY() {}
    QUERY(int _l, int _r, int _val, int _type) {
        l = _l; r = _r; val = _val; type = _type;
    }
};
vector<QUERY> vQ;

struct SEGMENT {
    int st[N*4];

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

    int get(int i, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return st[i];

        int m = (l+r) >> 1;
        return get(i*2, l, m, u, v) + get(i*2+1, m+1, r, u, v);
    }
} myTree;

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        vQ.push_back(QUERY(i, i, a, 1));
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        vQ.push_back(QUERY(l, r, i, 2));
    }

    sort(vQ.begin(), vQ.end(), [&] (QUERY a, QUERY b) {
        return a.r < b.r || (a.r == b.r && a.type < b.type);
    });

    for (QUERY &i: vQ) {
        int l = i.l, r = i.r, val = i.val, type = i.type;
        if (type == 1) {
            myTree.upd(1, 1, n, l, 1);
            if (pre[val] > 0) myTree.upd(1, 1, n, pre[val], 0);
            pre[val] = l;
        }
        else ans[val] = myTree.get(1, 1, n, l, r);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
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
