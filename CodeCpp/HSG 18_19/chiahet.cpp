#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+9;
int st[maxN*4], n, m;

void update(int i, int l, int r, int u, int v) {
    if (u < l || r < u) return;
    if (l == r) {
        st[i] = v;
        return;
    }
    int m = l+(r-l)/2;
    update(i*2, l, m, u, v);
    update(i*2+1, m+1, r, u, v);

    st[i] = st[i*2] + st[i*2+1];
}

int get(int i, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) {
        return st[i];
    }
    int m = l+(r-l)/2;
    return get(i*2, l, m, u, v) + get(i*2+1, m+1, r, u, v);
}

int main() {
    freopen("chiahet.inp", "r", stdin);
    freopen("chiahet.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a%6==0)
            update(1, 1, n, i, 1);
    }
    // for (int i = 1; i <= n*4; i++) cout << st[i] << ' '; cout << endl;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        cout << get(1, 1, n, x, y) << endl;
    }
}