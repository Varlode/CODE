#include<bits/stdc++.h>
using namespace std;

int n, q, st[1000000];

void update(int idx, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    if (l == r) {
        st[idx] = v;
        return;
    }
    int m = (l + r) / 2;
    update(idx*2, l, m, i, v);
    update(idx*2 + 1, m + 1, r, i, v);
    st[idx] = max(st[idx*2], st[idx*2 + 1]);
}

int get(int idx, int l, int r, int u, int v) {
    if (v < l || r < u) return -1e9;
    if (u <= l && r <= v) return st[idx];
    int m = (l + r) / 2;
    return max(get(idx*2, l, m, u, v), get(idx*2 + 1, m + 1, r, u, v));
}

int main() {
    freopen("cophieu.inp", "r", stdin);
    freopen("cophieu.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(1, 1, n, i, x);
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int req; cin >> req;
        int x, y; cin >> x >> y;
        if (req == 0) {
            update(1, 1, n, x, y);
        } else {
            cout << get(1, 1, n, x, y) << endl;
        }
    }
}