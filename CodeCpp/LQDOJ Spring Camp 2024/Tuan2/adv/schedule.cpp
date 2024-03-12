#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n;
pair<int, int> a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    sort(a+1, a+1+n, [&](auto a, auto b) {
        return a.second*b.first < a.first*b.second;
    });
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) sum += a[i].first;
    for (int i = 1; i <= n; i++) {
        ans += sum*a[i].second;
        sum -= a[i].first;
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
