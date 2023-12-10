/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 101010;
int n, q;
int a[N];

struct BIT {
    set< pair<int, int> > bag[N];

    void upd(int u, int v) {
        int idx = u;
        while (idx <= n) {
            bag[idx].insert({v, u});
            idx += idx & (-idx);
        }
    }

    void rpl(int u, int v) {
        int idx = u;
        while (idx <= n) {
            bag[idx].erase({a[u], u});
            bag[idx].insert({v, u});
            idx += idx & (-idx);
        }
        a[u] = v;
    }

    set< pair<int, int> > get(int u) {
        int idx = u;
        set< pair<int, int> > ans;
        while (idx > 0) {
            ans.insert(bag[idx].begin(), bag[idx].end());
            idx -= idx & (-idx);
        }
        return ans;
    }

    void qry(int u, int v) {
        set< pair<int, int> > ans;
        for (auto &p : get(v)) if (p.second >= u)
            ans.insert(p);
        for (auto &p : ans) cerr << p.first << ' '; cerr << '\n';
        pair<int, int> ret = *ans.begin();
        cout << ret.first << '\n';
    }
} bit;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.upd(i, a[i]);
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int j, x, y;
        cin >> j >> x >> y;
        if (j == 0) bit.rpl(x, y);
        else bit.qry(x, y);
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
