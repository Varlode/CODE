/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    dp[i][x] = (j, y) la:
         xet toi vi tri i, voi thung hang 1 co x dung tich
         tong cong j thung hang, va thung hang 2 co y dung tich


*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define ii pair<int, int>
#define fi first
#define se second

const int M = 1e6+1;
int L, n;
int a[M];

void init(void) {
    cin >> L >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

struct ONE {

bool check(void) {
    return n <= 20;
}

void solve(void) {
    int ans = n;
    for (int mask = 0; mask < (1 << n); mask++) {
        int A, B; A = B = 0;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1) A += a[i+1];
            else B += a[i+1];
        ans = min(ans, (A + L - 1) / L + (B + L - 1) / L);
    }
    cout << ans;
}

} one;

struct TWO {

bool check(void) {
    for (int i = 1; i <= n; i++) if (a[i] > 2) return false;
    return true;
}

void solve(void) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    cout << (sum + L - 1) / L;
}

} two;

struct THREE {

ii dp[10001][5001];

ii calc(int j, int y, int v) {
    y += v;
    if (y > L) {
        j++;
        y = v;
    }
    return ii(j, y);
}

void solve(void) {
    for (int i = 0; i <= n; i++) for (int x = 0; x <= L; x++)
        dp[i][x] = ii(inf, 0);
    for(int x = 0; x <= L; x++) dp[0][x] = ii(1, 0);
    dp[0][0] = ii(0, 0);

    for (int i = 0; i < n; i++) for (int x = 0; x <= L; x++) {
        ii nxt = calc(dp[i][x].fi, x, a[i+1]);
        dp[i+1][nxt.se] = min(dp[i+1][nxt.se], ii(nxt.fi, dp[i][x].se));
        nxt = calc(dp[i][x].fi, dp[i][x].se, a[i+1]);
        dp[i+1][x] = min(dp[i+1][x], ii(nxt.fi, nxt.se));
    }

    int ans = inf;
    for (int x = 0; x <= L; x++) ans = min(ans, dp[n][x].fi);
    cout << ans;
}

} three;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    init();
//    if (one.check()) return one.solve(), 0;
//    if (two.check()) return two.solve(), 0;
    return three.solve(), 0;
}
