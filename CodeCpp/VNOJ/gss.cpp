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
const int MOD = 1e9 + 7;
int n, q, a[N];

struct node {
    int sum, mxSum, pref, suf;
    node() {
        sum = 0;
        mxSum = pref = suf = -1e9;
    }
} st[N*4];

node combine(const node l, const node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum+r.pref);
    res.suf = max(l.suf+r.sum, r.suf);
    res.mxSum = max({l.mxSum, r.mxSum, l.suf+r.pref});
    return res;
}

void build(int i, int l, int r) {
    if (l == r) {
        st[i].sum = st[i].mxSum = st[i].pref = st[i].suf = a[l];
        return;
    }
    int m = (l+r) >> 1;

    build(i*2, l, m);
    build(i*2+1, m+1, r);

    st[i] = combine(st[i*2], st[i*2+1]);
}

node get(int i, int l, int r, int u, int v) {
    if (v < l || r < u) return node();
    if (u <= l && r <= v) return st[i];

    int m = (l+r) >>  1;

    return combine(get(i*2, l, m, u, v), get(i*2+1, m+1, r, u, v));
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        cout << get(1, 1, n, l, r).mxSum << '\n';
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
