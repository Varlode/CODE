#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, m;
long long ans = 3e9, a[N], b[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b+1, b+1+m);
    int j = 1;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, abs(a[i] - b[j]));
        while (j+1 <= m && abs(a[i+1] - b[j]) > abs(a[i] - b[j+1])) {
            j++;
            ans = min(ans, abs(a[i] - b[j]));
        }
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
