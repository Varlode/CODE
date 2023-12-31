/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    NX 1: thay rang thoi gian cang nhieu thi cang thoa man
    => co them giam thoi gian dan dan de tim kq => chat nhi phan

    NX 2: Khi chat nhi phan, mot canh thay doi chi thay doi gia tri khi
    d tu 1 toi no va no toi dinh xa nhat lon hon mid

    mot so luu y khi code:
        bien money hay khai bao toan cuc
        bien money thay doi trong ham nen hay luu gia tri goc

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define i3 pair<int, ii >
#define fi first
#define se second

const int N = 1e5+1;
int n, k, money, dGo[N], dMx[N];
vector< i3 > adj[N];

void preDfs(int u, int p = -1) {
    for (i3 &i: adj[u]) {
        int v = i.fi, A = i.se.fi;
        if (v == p) continue;
        preDfs(v, u);
        dMx[u] = max(dMx[u], dMx[v] + A);
    }
}

bool check(int m, int u, int p = -1) {
    if (adj[u].size() == 1 && p != -1) return (dGo[u] <= m);
    for (i3 &i: adj[u]) {
        int v = i.fi, A = i.se.fi, B = i.se.se;
        if (v == p) continue;

        int need = max(0, dGo[u] + A + dMx[v] - m);

        if (need <= A-B) {
            if (money < need) return false;
            money -= need;
        }
        else {
            need = A-B;
            if (money < need) return false;
            money -= need;
            dGo[v] = dGo[u] + B;
            if (check(m, v, u) == false) return false;
        }
    }
    return true;
}

void solve(void) {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v, A, B; cin >> u >> v >> A >> B;
        adj[u].push_back(i3(v, ii(A, B)));
        adj[v].push_back(i3(u, ii(A, B)));
    }

    preDfs(1);

    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int m = (l+r) >> 1;
        money = k;
        if (check(m, 1)) {
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }

    cout << ans;
}

int main(void) {
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
