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
int n, a[N], b[N], f[N], g[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(b, 0x3f, sizeof b);
    for (int i = n; i >= 1; i--) {
        int k = lower_bound(b+1, b+1+n, -a[i]) - b;
        b[k] = -a[i];
        f[i] = k;
    }

    memset(b, 0x3f, sizeof b);
    for (int i = n; i >= 1; i--) {
        int k = lower_bound(b+1, b+1+n, a[i]) - b;
        b[k] = a[i];
        g[i] = k;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i] + g[i] - 1);
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
