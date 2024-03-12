#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, x[N], y[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    sort(x+1, x+1+n);
    sort(y+1, y+1+n);
    int ans = 1e9;
    for (int i = 1; i < n; i++) {
        ans = min({ans, x[i+1]-x[i], y[i+1]-y[i]});
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
