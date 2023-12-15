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

const int N = 1e6+1;
int l, r, prime[N];
map<int, int> cnt;

void solve() {
    cin >> l >> r;
    for (int i = 1; i <= r; i++) prime[i] = 1;
    for (int i = 2; i <= r; i++) if (prime[i] == 1) {
        for (int j = i; j <= r; j += i)
            prime[j] *= i;
    }

    long long ans = 0;
    for (int i = l; i <= r; i++) ++cnt[prime[i]];
    for (auto &p : cnt) ans += 1ll*p.second*(p.second-1)/2;
    cout << ans;
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
