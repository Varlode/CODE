#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, K, a[N];

bool check(int m) {
    int cnt = 1, pre = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - pre > 2*m) {
            cnt++;
            pre = a[i];
        }
    }
    return cnt <= K;
}

void solve() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int l = 1, r = 1e9, ans = -1;
    while (l <= r) {
        int m = (l+r) >> 1;
        if (check(m)) {
            ans = m;
            r = m-1;
        }
        else l = m+1;
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
