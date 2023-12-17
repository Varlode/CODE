/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int n;
int p[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p[p[p[i]]] == i) ans = 1;
    }
    if (ans) cout << "<3\n";
    else cout << "</3\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
