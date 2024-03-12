#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
const int MOD = 1e9+7;
int n;
int a[N], suf[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i+1] + a[i];
        suf[i] %= MOD;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += 1ll * a[i] * suf[i+1] % MOD;
        ans %= MOD;
    }
    cout << ans;
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    solve();
}
