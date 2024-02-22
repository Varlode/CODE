#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
const int inf = 1e9;
int a[N], n;

struct SEGMENT {
    int nONE[N*4], nTWO[N*4];

    void build(int i, int l, int r) {
        if (l > r) return;
        if (l == r) {
            nONE[i] = l;
            nTWO[i] = l;
            return;
        }
        int m = (l+r) >> 1;
        build(i*2, l, m);
        build(i*2+1, m+1, r);
        nONE[i] = (a[nONE[i*2]] < a[nONE[i*2+1]])? nONE[i*2] : nONE[i*2+1];
        nTWO[i] = (a[nTWO[i*2]] > a[nTWO[i*2+1]])? nTWO[i*2] : nTWO[i*2+1];
    }

    pair<int, int> get(int i, int l, int r, int u, int v) {
        if (r < u || v < l) return {n+1, 0};
        if (u <= l && r <= v) return {nONE[i], nTWO[i]};
        int m = (l+r) >> 1;
        pair<int, int> left = get(i*2, l, m, u, v);
        pair<int, int> right = get(i*2+1, m+1, r, u, v);
        return {
            (a[left.first] < a[right.first])? left.first : right.first,
            (a[left.second] > a[right.second])? left.second : right.second
        };
    }
} myTree;

void solve() {
    cin >> n;
    a[0] = -inf; a[n+1] = inf;
    for (int i = 1; i <= n; i++) cin >> a[i];
    myTree.build(1, 1, n);
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        pair<int, int> p = myTree.get(1, 1, n, l, r);
        if (a[p.first] == a[p.second]) {
            cout << "-1 -1\n";
        }
        else cout << p.first << ' ' << p.second << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
