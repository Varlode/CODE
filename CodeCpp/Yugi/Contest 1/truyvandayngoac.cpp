/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+1;
int n, q, a[N];

struct node {
    int op, cl, ok;
    node() {
        op = cl = ok = 0;
    }
    node(int a, int b) {
        op = a;
        cl = b;
    }
} st[N*4];

node operator + (const node a, const node b) {
    node res;
    res.ok = min(a.op, b.cl);
    res.op = a.op+b.op-res.ok;
    res.cl = a.cl+b.cl-res.ok;
    return res;
}

void build(int i, int l, int r) {
    if (l == r) {
        if (a[l] == 1) st[i] = node(1, 0);
        else st[i] = node(0, 1);
        return;
    }
    int m = (l+r) >> 1;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    st[i] = st[i*2]+st[i*2+1];
}

void upd(int i, int l, int r, int u) {
    if (u < l || r < u) return;
    if (l == r) {
        if (a[l] == 1) st[i] = node(1, 0);
        else st[i] = node(0, 1);
        return;
    }
    int m = (l+r) >> 1;
    upd(i*2, l, m, u);
    upd(i*2+1, m+1, r, u);
    st[i] = st[i*2]+st[i*2+1];
}

node get(int i, int l, int r, int u, int v) {
    if (v < l || r < u) return node();
    if (u <= l && r <= v) return st[i];
    int m = (l+r) >> 1;
    return get(i*2, l, m, u, v)+get(i*2+1, m+1, r, u, v);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '(') a[i] = 1;
        else a[i] = -1;
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int p; cin >> p;
        if (p == 0) {
            int x; cin >> x;
            a[x] *= -1;
            upd(1, 1, n, x);
        }
        else {
            int l, r; cin >> l >> r;
            node res = get(1, 1, n, l, r);
            cout << (res.op == 0 && res.cl == 0);
        }
    }

}

main() {
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
