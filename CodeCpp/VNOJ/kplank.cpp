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
int n, a[N], l[N], r[N], ans;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> s;
    s.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (s.size() && a[s.back()] >= a[i]) s.pop_back();
        l[i] =s.back();
        s.push_back(i);
    }

    s.clear();
    s.push_back(n+1);
    for (int i = n; i >= 1; i--) {
        while (s.size() && a[s.back()] >= a[i]) s.pop_back();
        r[i] = s.back();
        s.push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (r[i]-l[i]-1 < a[i]) continue;
        ans = max(ans, min(a[i], r[i]-l[i]-1));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
