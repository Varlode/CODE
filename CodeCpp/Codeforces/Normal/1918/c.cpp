#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, r; cin >> a >> b >> r;
    if (a < b) swap(a, b);
    if (r == 0) {
        cout << a-b << '\n';
        return;
    }
    long long LOG = __lg(r), res = 0;
    for (long long i = LOG; i >= 0; i--) {
        if (r >= (1ll << i) && (a >> i & 1) > (b >> i & 1) && (a^res^(1ll << i)) >= (b^res^(1ll << i))) {
            r -= 1ll << i;
            res += 1ll << i;
        } 
    }
    cout << (a^res) - (b^res) << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}