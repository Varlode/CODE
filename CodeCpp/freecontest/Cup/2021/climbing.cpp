/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010101;
int n, m, c, haveRes, a[N];

void solve() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];

    deque<int> dqMx, dqMn;
    for (int i = 1; i < m; i++) {
        while (dqMx.size() && a[dqMx.back()] <= a[i]) dqMx.pop_back();
        while (dqMn.size() && a[dqMn.back()] >= a[i]) dqMn.pop_back();

        dqMx.push_back(i);
        dqMn.push_back(i);
    }
    for (int i = m; i <= n; i++) {
        if (dqMx.size() && dqMx.front() <= i-m) dqMx.pop_front();
        if (dqMn.size() && dqMn.front() <= i-m) dqMn.pop_front();

        while (dqMx.size() && a[dqMx.back()] <= a[i]) dqMx.pop_back();
        while (dqMn.size() && a[dqMn.back()] >= a[i]) dqMn.pop_back();

        dqMx.push_back(i);
        dqMn.push_back(i);

        int mx = a[dqMx.front()], mn = a[dqMn.front()];
        if (mx - mn <= c) {
            cout << i-m+1 << '\n';
            haveRes = 1;
        }
    }
    if (!haveRes) cout << "NONE\n";
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
