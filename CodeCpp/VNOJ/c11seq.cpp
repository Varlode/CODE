/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 3e5+100;
int n, L, R;
int a[N];
vector< long long > val;

struct BIT {
    int valBIT[N];
    void upd(int u, int v) {
        for (; u < N; u += u&(-u)) valBIT[u] += v;
    }

    long long get(int u) {
        long long res = 0;
        for (; u > 0; u -= u&(-u)) res += valBIT[u];
        return res;
    }
} bit;

void solve() {
    cin >> n >> L >> R;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        val.push_back(sum-R);
        val.push_back(sum-L);
        val.push_back(sum);
    }
    val.push_back(0);

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    sum = 0;
    int tmp = lower_bound(val.begin(), val.end(), 0) - val.begin() + 1;
    bit.upd(tmp, 1);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        int l = lower_bound(val.begin(), val.end(), sum-L) - val.begin() + 1;
        int r = lower_bound(val.begin(), val.end(), sum-R) - val.begin() + 1;
        int s = lower_bound(val.begin(), val.end(), sum) - val.begin() + 1;
        ans +=   bit.get(l) - bit.get(r-1);
        bit.upd(s, 1);
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
