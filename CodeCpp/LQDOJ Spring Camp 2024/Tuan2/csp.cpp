#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, m, pref[N], cnt[N];
long long ans;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i <= m; i++) pref[i] = cnt[i]+pref[i-1];
    for (int i = 1; i <= m; i++) {
        if (cnt[i]) {
            if (i < m-i) ans += 1ll*cnt[i]*(pref[m-i]-pref[i]);
            if (i*2 <= m) ans += 1ll*cnt[i]*(cnt[i]-1)/2;
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
