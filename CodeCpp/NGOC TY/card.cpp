#include <bits/stdc++.h>
using namespace std;

const int N = 2020202;
int n, k;
char a[N];
int f[N], cnt[N];
set< pair<int,int> > s;

void solve() {   
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    reverse(a+1, a+n+1);
    for (int i = n; i >= 1; i--) {
        if (a[i] == '1') cnt[i] = cnt[i+1] + 1;
        else cnt[i] = cnt[i+1];
    }
    f[n+1] = 0;
    s.insert({0, n+1});
    for (int i = n; i >= 1; i--) {
        while (true) {
            pair<int,int> cur = *s.begin();
            if (cur.second <= i + k) {
                f[i] = cnt[i] - cur.first;
                break;
            }
            else s.erase(s.begin());
        }
        s.insert({f[i], i});
    }
    if (f[1] == cnt[1] / 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << min(f[1], cnt[1] - f[1]) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "card"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
