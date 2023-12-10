/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int n, h;
int cnt[N], mark[N];

void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (i&1) {
            mark[1]++;
            mark[a+1]--;
        }
        else mark[h-a+1]++;

    }
    int ans = 1e9;
    for (int i = 1; i <= h; i++) {
        mark[i] += mark[i-1];
        cnt[mark[i]]++;
        ans = min(ans, mark[i]);
    }
    cout << ans << ' ' << cnt[ans];
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
