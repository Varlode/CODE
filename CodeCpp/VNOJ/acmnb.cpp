/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

int n, sum = 0;

void solve() {
    cin >> n;
    vector<int> c(2*n);
    for (int &u: c) {
        int a, b;
        cin >> a >> b;
        sum += a;
        u = b-a;
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        sum += c[i];
    }
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
