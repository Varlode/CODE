#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s; cin >> s;
    while (*s.begin() == 'W') s.erase(s.begin());
    reverse(s.begin(), s.end());
    while (*s.begin() == 'W') s.erase(s.begin());
    cout << (int) s.size() << '\n';
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
