/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    NX 1: ta thay rang neu v thoa man thi u < v cung thoa man
    -> dung chat nhi phan ket qua
    NX 2: ban chat cua bai toan la co dinh gia tri phong 1,
    va cac phong con lai lon phong 1
    vi khong mat tinh tong quat ta se co 1 day tang ko ngat

    goi f[x][y] = (i, value) la x may ban va y may tinh bang da dung
    cho i phong truoc do, va val la gia tri cua phong tiep theo
    neu val > mid co the tiep tuc phong tiep theo
    moi f[x][y] ta can tim max phong da xep truoc
    cho den gia tri cua phong tiep theo

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 1001;
int x, a, y, b, n;
pair<int, int> dp[N][N];

void init(void) {
    cin >> x >> a >> y >> b >> n;
}

ii nxt(ii cur, int val, int m) {
    cur.se += val;
    if (cur.se >= m) {
        cur.fi++;
        cur.se = 0;
    }
    return cur;
}

bool check(int m) {
    for (int i = 0; i <= x; i++) for (int j = 0; j <= y; j++)
        dp[i][j] = ii(0, 0);
    for (int i = 0; i <= x; i++) for (int j = 0; j <= y; j++) {
        if (dp[i][j].fi == n) return 1;
        if (i < x) dp[i+1][j] = max(dp[i+1][j], nxt(dp[i][j], a, m));
        if (j < y) dp[i][j+1] = max(dp[i][j+1], nxt(dp[i][j], b, m));
    }
    return 0;
}

void solve(void) {
    int l = 1, r = (x*a+y*b)/n, ans = 0;
    while (l <= r) {
        int m = (l+r) >> 1;
        if (check(m)) {
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }
    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 2;
    // cin >> t;
    while (t--) {
        init();
        solve();
    }
}
