/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
const int MOD = 1e9+7;
int f[N], g[N], n;

void init() {
    f[1] = g[1] = 1;
    for (int i = 2; i < N; i++) {
        f[i] = (f[i-1]*4ll % MOD + g[i-1]) % MOD;
        g[i] = (f[i-1] + g[i-1]*2ll % MOD) % MOD;
    }
}

void solve() {
    cin >> n;
    cout << (f[n]+g[n]) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
}
