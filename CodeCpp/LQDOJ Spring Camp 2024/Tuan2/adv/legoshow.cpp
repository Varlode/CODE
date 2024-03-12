#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n, k, a[N], f[N], g[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << 1;
        return;
    }
    sort(a+1, a+1+n);
    int l = 1; f[1] = 1;
    for (int r = 2; r <= n; r++) {
        while (l < r && a[r] - a[l] > k) l++;
        f[r] = max(f[r-1], r-l+1);
    }

    l = n; g[n] = 1;
    for (int r = n-1; r >= 1; r--) {
        while (l > r && a[l] - a[r] > k) l--;
        g[r] = max(g[r+1], l-r+1);
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, f[i] + g[i+1]);
    }
    cout << ans;
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
