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
int n, q, a[N];
long long dp[N];

struct SEQMENT {
    long long st[N*4], lazy[N*4];

    void down(int i) {
        st[i*2] += lazy[i];
        lazy[i*2] += lazy[i];

        st[i*2+1] += lazy[i];
        lazy[i*2+1] += lazy[i];

        lazy[i] = 0;
    }

    void build(int i, int l, int r) {
        if (l == r) {
            st[i] = a[l];
            return;
        }
        int m = (l+r) >> 1;
        build(i*2, l, m);
        build(i*2+1, m+1, r);
        st[i] = max(st[i*2], st[i*2+1]);
    }

    void upd(int i, int l, int r, int u, long long k) {
        if (u < l || r < u) return;
        if (l == r) {
            st[i] = k;
            return;
        }
        int m = (l+r) >> 1;
//        down(i);
        upd(i*2, l, m, u, k);
        upd(i*2+1, m+1, r, u, k);
        st[i] = max(st[i*2], st[i*2+1]);
    }

    long long get(int i, int l, int r, int u, int v) {
        if (v < l || r < u) return -1e18;
        if (u <= l && r <= v) return st[i];
        int m = (l+r) >>  1;
//        down(i);
        return max(get(i*2, l, m, u, v), get(i*2+1, m+1, r, u, v));
    }
} myTree;

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], myTree.get(1, 0, n, i-q, i-1)+a[i]);
        myTree.upd(1, 0, n, i, dp[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;
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
