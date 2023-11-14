#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N];

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mx = 1, mn = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[mx]) mx = i;
        if (a[i] < a[mn]) mn = i;
    }
    int ans = 1e9;
    ans = min({ans, n-min(mn, mx)+1, max(mn, mx)});
    ans = min({ans, n-mn+1 + mx, n-mx+1 + mn});
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int nt; cin >> nt;
    while (nt--) solve();
}