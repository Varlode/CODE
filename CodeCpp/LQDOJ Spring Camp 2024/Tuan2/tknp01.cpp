#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, k;
set<int> s;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        s.insert(a);
    }
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        if (s.find(x) != s.end()) cout << "YES\n";
        else cout << "NO\n";
    }
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
