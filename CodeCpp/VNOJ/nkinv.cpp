/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 60001;
int n, a, ans;

struct BIT {
    int label[N];

    void build() {
        memset(label, 0, sizeof label);
    }

    void upd(int u) {
        for (int idx = u; idx > 0; idx -= idx&(-idx))
            label[idx]++;
    }

    int get(int u) {
        int res = 0;
        for (int idx = u; idx <= n; idx += idx&(-idx))
            res += label[idx];
        return res;
    }
} bit;

void solve() {
    cin >> n;
    bit.build();
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ans += bit.get(a+1);
        bit.upd(a);
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
