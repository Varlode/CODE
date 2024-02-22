/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    max - min lon nha khi sap xep thanh chuoi tang/giam
    suy ra dung bitmask de luu
    dp[i][mask] la khi xe toi cot thu i cac toa nha da co la
    dp[i'][mask'] voi mask la 1 bit da bat trong mask,
    va i' la i-s[i] (so cot xay toa nha bit bat)

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

const int N = 1e5+1;
int n, m, P, C;
int a[N], s[10];

long long f[N][(1 << 6)];

inline long long sqr(long long x) {
    return 1ll*x*x;
}

void init(void) {
    cin >> n >> m >> P >> C;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> s[i];
}

void solve(void) {
    for (int mask = 0; mask < (1 << m); mask++) f[0][mask] = -inf;
    f[0][0] = 0;

    sort(a+1, a+1+n);

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            f[i][mask] = f[i-1][mask];
            for (int j = 0; j < m; j++) if ((mask >> j & 1) && i >= s[j]) {
                long long profit = P - sqr(a[i] - a[i-s[j]+1]) * C;
                f[i][mask] = max(f[i][mask], f[i-s[j]][mask & ~(1 << j)] + profit);
                f[i][mask] = max(f[i][mask], f[i-s[j]][mask] + profit);
            }
        }
    }
    cout << f[n][(1 << m)-1];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    init();
    solve();
}
