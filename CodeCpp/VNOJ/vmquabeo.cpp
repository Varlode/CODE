/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n, L, D;
int a[N];

deque<int> mx, mn;

void add_deque(int i) {
    while(mx.size() && a[mx.back()] <= a[i]) mx.pop_back();
    while(mn.size() && a[mn.back()] >= a[i]) mn.pop_back();
    mx.push_back(i);
    mn.push_back(i);
}

void remove_deque(int i) {
    if (mx.front() <= i) mx.pop_front();
    if (mn.front() <= i) mn.pop_front();
}

void solve() {
    cin >> n >> L >> D;
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long ans = 0;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        add_deque(r);
        while (l <= r && a[mx.front()] - a[mn.front()] > D) {
            remove_deque(l);
            l++;
        }
        if (r-l+1 >= L) ans += r-l+1-L;
    }
    cout << ans;
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
