#include<bits/stdc++.h>
using namespace std;

int n, q;

struct node {
    int max1, max2;
} bit[400000];

node operator + (const node& a, const node& b) {
    node res;

    res.max1 = max(a.max1, b.max1);
    res.max2 = max(min(a.max1, b.max1), max(a.max2, b.max2));

    return res;
}

void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    if (l == r) {
        bit[id].max1 = v;
        bit[id].max2 = 0;
        return;
    }
    int m = l + (r - l) / 2;
    update(id*2, l, m, i, v);
    update(id*2 + 1, m+1, r, i, v);
    bit[id] = bit[id*2] + bit[id*2 + 1];
}

node query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return bit[0];
    if (u <= l && r <= v) return bit[id];

    int m = l + (r - l) / 2;
    return query(id*2, l, m, u, v) + query(id*2 + 1, m+1, r, u, v);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        update(1, 1, n, i, t);
    }
    for (int i = 1; i <= q; i++) {
        int L, R; cin >> L >> R;
        node ans = query(1, 1, n, L, R);
        cout << ans.max1+ans.max2 << endl;
    }
}