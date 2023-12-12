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
int n, q, a[N];

struct SEQMENT {
    vector<int> st[N*4];

    void build() {
        for (int i = 1; i <= n; i++) st[i].clear();
    }

    void upd(int i, int l, int r) {
        if (l == r) {
            st[i].push_back(a[l]);
            return;
        }
        int m = (l+r) >> 1;

        upd(i*2, l, m);
        upd(i*2+1, m+1, r);
        st[i].resize((int)st[i*2].size() + (int)st[i*2+1].size());
        merge(st[i*2].begin(), st[i*2].end(), st[i*2+1].begin(), st[i*2+1].end(), st[i].begin());
    }

    int get(int i, int l, int r, int u, int v, int k) {
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) {
            int pos = upper_bound(st[i].begin(), st[i].end(), k) - st[i].begin();
            return (int) st[i].size() - pos;
        }
        int m = (l+r) >>  1;

        return get(i*2, l, m, u, v, k) + get(i*2+1, m+1, r, u, v, k);
    }
} myTree;

void solve() {
    cin >> n;
    myTree.build();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    myTree.upd(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y, k; cin >> x >> y >> k;
        cout << myTree.get(1, 1, n, x, y, k) << '\n';
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
