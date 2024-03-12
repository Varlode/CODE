#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, K, a[N], mx;
long long ans;

void solve() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ans += a;
        mx = max(mx, a);
    }
    cout << max(1ll, ans-mx+max(0, mx-K)+1);
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
