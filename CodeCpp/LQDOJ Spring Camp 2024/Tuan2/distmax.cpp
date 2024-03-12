#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
const int N = 1e6+10;
int n, x[N];
pair<int, int> a[N], mn[N], mx[N];

bool check(int m) {
    for (int i = 1; i <= n; i++) {
        int l = upper_bound(x, x+1+n, a[i].first-m) - x - 1;
        int r = lower_bound(x, x+1+n, a[i].first+m) - x;
        if (l > 0) {
            if (abs(mx[l].first - a[i].second) >= m ||
                abs(mn[l].first - a[i].second) >= m)
                return true;
        }
        if (r < n+1) {
            if (abs(mx[r].second - a[i].second) >= m ||
                abs(mn[r].second - a[i].second) >= m)
                return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a+1, a+1+n);

    for (int i = 1; i <= n; i++) x[i] = a[i].first;

    mn[0].first = 1e9+1;
    mn[n+1].second = 1e9+1;
    for (int i = 1; i <= n; i++) {
        mn[i].first = min(mn[i-1].first, a[i].second);
        mx[i].first = max(mx[i-1].first, a[i].second);
    }
    for (int i = n; i >= 1; i--) {
        mn[i].second = min(mn[i+1].second, a[i].second);
        mx[i].second = max(mx[i+1].second, a[i].second);
    }

    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (check(m)) {
            ans = m;
            l = m+1;
        }
        else r = m-1;
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
