/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
int n, p, a[N];
vector<long long> val;

struct SEQMENT {
    int tVal[N*2*4];

    void build() {
        memset(tVal, 0x3f, sizeof tVal);
    }

    void upd(int i, int l, int r, int u, int v) {
        if (r < u || u < l) return;
        if (l == r) {
            tVal[i] = min(tVal[i], v);
            return;
        }
        int m = (l+r) >> 1;
        upd(i*2, l, m, u, v);
        upd(i*2+1, m+1, r, u, v);
        tVal[i] = min(tVal[i*2], tVal[i*2+1]);
    }

    int get(int i, int l, int r, int u, int v) {
        if (v < l || r < u) return 0x3f3f3f3f;
        if (u <= l && r <= v) return tVal[i];
        int m = (l+r) >> 1;
        return min(get(i*2, l, m, u, v), get(i*2+1, m+1, r, u, v));
    }
} mytree;

void solve() {
    cin >> n >> p;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        val.push_back(sum);
        val.push_back(sum-p);
    }
    val.push_back(0);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    int sz = (int) val.size();

    sum = 0;
    mytree.build();

    int tmp = lower_bound(val.begin(), val.end(), 0) - val.begin() + 1;
    mytree.upd(1, 1, sz, tmp, 0);

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        int s = lower_bound(val.begin(), val.end(), sum) - val.begin() + 1;
        int r = lower_bound(val.begin(), val.end(), sum-p) - val.begin() + 1;
        ans = max(ans, i-mytree.get(1, 1, sz, 1, r));
        mytree.upd(1, 1, sz, s, i);
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
