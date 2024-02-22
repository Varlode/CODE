#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector< pair<int, int> > a;
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;    
    for (int i = 0; i < n; i++) cin >> a[i].second;
    sort(a.begin(), a.end(), [&] (auto x, auto y) {
        return x.first+x.second < y.first+y.second;
    });
    for (int i = 0; i < n; i++) cout << a[i].first << ' ';
    cout << '\n';    
    for (int i = 0; i < n; i++) cout << a[i].second << ' ';
    cout << '\n';    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}