/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 301;
int n, m;
int l[N], r[N];
long long shouldChoose[N], mn[N], pref[N];

void init(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        shouldChoose[i] = -1e18;
        mn[i] = 1e18;
        while (k--) {
            long long v, c; cin >> v >> c;
            shouldChoose[i] = max(shouldChoose[i], v-c);
            mn[i] = min(mn[i], c);
        }
        pref[i] += mn[i] + pref[i-1];
    }
}

namespace two {

bool check(void) {
    // lam sao de check?;
    return true;
}

void solve(void) {
    long long ans = 0;
    for (int j = 1; j <= m; j++) {
        long long res = -1e18, sum = pref[r[j]]-pref[l[j]-1];
        for (int i = l[j]; i <= r[j]; i++) {
            res = max(res, sum-mn[i] + shouldChoose[i]);
        }
        ans += res;
    }
    cout << ans;
}

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "genarray"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        init();
        if (two::check()) return two::solve(), 0;
    }
}
