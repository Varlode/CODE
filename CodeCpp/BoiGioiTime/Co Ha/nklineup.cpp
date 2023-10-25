#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, q;

struct node {
    int ma, mi;
    node() {
        ma = -1e9; mi = 1e9;
    }
    node(int a, int b) {
        ma = a, mi = b;
    }
};

node merge(node a, node b) {
    node ans;
    ans.ma = max(a.ma, b.ma);
    ans.mi = min(a.mi, b.mi);
    return ans;
}

node st[4*N];

void update(int idx, int l, int r, int u, int v) {
    if (u < l || r < u) return;
    if (l == r) {
        st[idx].ma = st[idx].mi = v;
        return;
    }
    int m = l+(r-l)/2;
    update(idx*2, l, m, u, v);
    update(idx*2+1, m+1, r, u, v);

    st[idx] = merge(st[idx*2], st[idx*2+1]); 
}

node get(int i, int l, int r, int u, int v) {
    if (v < l || r < u) return node(-1e9, 1e9);
    if (u <= l && r <= v) return st[i];
    int m = l+(r-l)/2;
    return merge(get(i*2, l, m, u, v), get(i*2+1, m+1, r, u, v));
}

int main() {
    freopen("nklineup.inp", "r", stdin);
    freopen("nklineup.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        update(1, 1, n, i, a);
    }

    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        node ans = get(1, 1, n, x, y);
        cout << abs(ans.ma - ans.mi) << endl;
    }
}