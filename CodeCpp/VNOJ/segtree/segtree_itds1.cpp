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
const int LIMIT = 1e9;
int n, q, a[N];

multiset<int> st[N*4];

void build(int i, int l, int r) {
    st[i].clear();
    if (l == r) {
        st[i].insert(a[l]);
        return;
    }
    int m = (l+r) >> 1;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    st[i].insert(st[i*2].begin(), st[i*2].end());
    st[i].insert(st[i*2+1].begin(), st[i*2+1].end());
}

void upd(int i, int l, int r, int u, int k) {
    if (u < l || r < u) return;
    if (l == r) {
        st[i].clear();
        st[i].insert(k);
        return;
    }
    int m = (l+r) >> 1;
    upd(i*2, l, m, u, k);
    upd(i*2+1, m+1, r, u, k);
    st[i].erase(st[i].find(a[u]));
    st[i].insert(k);
}

int get(int i, int l, int r, int u, int v, int k) {
    if (v < l || r < u) return LIMIT;
    if (u <= l && r <= v) {
        auto it = st[i].lower_bound(k);
        if (it == st[i].end()) return LIMIT;
        return *it;
    }
    int m = (l+r) >>  1;
    return min(get(i*2, l, m, u, v, k), get(i*2+1, m+1, r, u, v, k));
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int p; cin >> p;
        if (p == 1) {
            int u, v; cin >> u >> v;
            upd(1, 1, n, u, v);
            a[u] = v;
        }
        else {
            int l, r, k; cin >> l >> r >> k;
            int res = get(1, 1, n, l, r, k);
            if (res == LIMIT) cout << -1 << '\n';
            else cout << res << '\n';
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
