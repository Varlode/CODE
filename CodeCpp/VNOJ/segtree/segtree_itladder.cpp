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
int n, q, pref[N];

int st[N*4], sA[N*4], sB[N*4];

void add(int &a, int b) {
    a += b;
    if (a > MOD) a -= MOD;
}

void down(int i, int l, int r) {

    add(st[i], 1ll*(r-l+1)*sB[i] % MOD);
    add(st[i], 1ll*(pref[r] - pref[l-1])*sA[i] % MOD);

    if (l != r) {
        add(sA[i*2], sA[i]);
        add(sB[i*2], sB[i]);

        add(sA[i*2+1], sA[i]);
        add(sB[i*2+1], sB[i]);
    }
    sA[i] = sB[i] = 0;
}

void upd(int i, int l, int r, int u, int v, int A, int B) {
    down(i, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        add(sA[i], A);
        add(sB[i], (1ll*B-1ll*u*A+1ll*MOD*MOD) % MOD);
        down(i, l, r);
        return;
    }
    int m = (l+r) >> 1;

    upd(i*2, l, m, u, v, A, B);
    upd(i*2+1, m+1, r, u, v, A, B);
    st[i] = 0;
    add(st[i], st[i*2] + st[i*2+1]);
}

int get(int i, int l, int r, int u, int v) {
    down(i, l, r);
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[i];


    int m = (l+r) >>  1;

    int ans = 0;
    add(ans, get(i*2, l, m, u, v));
    add(ans, get(i*2+1, m+1, r, u, v));
    return ans;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + i;
    for (int i = 1; i <= q; i++) {
        int p; cin >> p;
        if (p == 1) {
            int u, v, A, B; cin >> u >> v >> A >> B;
            upd(1, 1, n, u, v, A, B);
        }
        else {
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << '\n';
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
