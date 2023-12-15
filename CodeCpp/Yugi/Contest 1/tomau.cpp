/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;
const int N = 5e3+1;

int fac[N];

int powmod(int a, int b) {
    if (a == 1 || b == 1) return a;
    int ret = powmod(a, b/2);
    if (b&1) return 1ll*ret*ret%MOD*1ll*a%MOD;
    return 1ll*ret*ret%MOD;
}

int inv(int a) {
    return powmod(a, MOD-2);
}

int cNk(int n, int k) {
    int ret = 1;
    for (int i = n-k+1; i <= n; i++) {
        ret *= i;
        ret %= MOD;
    }
    return 1ll*ret*inv(fac[k])%MOD;
}

void solve() {
    int n, k; cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i <= k; i++)
        fac[i] = 1ll*fac[i-1]*i%MOD;

    cout << cNk(n-k+1, k);
}

main() {
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
