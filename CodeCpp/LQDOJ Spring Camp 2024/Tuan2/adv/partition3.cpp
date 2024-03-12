#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n, k, a[N];

bool check(int m) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i]/m;
        if (cnt >= k) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int m = (l+r) >> 1;
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
