/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e4;
int n, k, a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    deque<int> dq;
    for (int i = 1; i < k; i++) {
        while (dq.size() && a[dq.back()] > a[i]) dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i <= n; i++) {
        if (dq.size() && dq.front() <= i-k) dq.pop_front();
        while (dq.size() && a[dq.back()] > a[i]) dq.pop_back();
        dq.push_back(i);
        cout << a[dq.front()] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
