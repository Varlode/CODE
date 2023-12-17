/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int s, n, a[N], ans;

void solve() {
    cin >> s >> n;
    for (int i = 0; i <= 15; i++) cin >> a[i];
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 15; j >= 0; j--) if ((i >> j) & 1) {
            sum += a[j];
            if (sum > s) break;
        }
        if (sum <= s) ans = max(ans, sum);
    }
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
