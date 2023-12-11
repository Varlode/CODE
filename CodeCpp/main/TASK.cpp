/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 15001;
int n, k, a[N], f[2*N], g[2*N];
vector<int> val;
void reset() {
    val.clear(); val.push_back(0);
    memset(f, 0, sizeof f);
    memset(g, 0x3f, sizeof g);
}

void check(int m) {
    reset();
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        val.push_back(sum);
        val.push_back(sum-m);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    int sz = (int) val.size();

    for (int i = 1; i <= n; i++) {
        sum += a[i];
        int iSum = lower_bound(val.begin(), val.end(), sum) - val.begin() + 1;
        int iSumM = lower_bound(val.begin(), val.end(), sum-m) - val.begin() + 1;
        f[i] = treeMx.get(1, 1, sz, iSumM - iSum);
    }
}

void solve() {
    cin >> n >> k;
    int mx = 0, mn = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }

    int l = min(mn*n, mn), r = max(mx, mx*mn);
    while (l <= r) {
        int m = (l+r) >> 1;
        if (check(m)) {
            ans = m;
            r = m-1;
        }
        else l = m+1;
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
