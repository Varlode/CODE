/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

int x, y;

void solve() {
    cin >> x >> y;
    y -= x;
    x -= x;
    int len = 1, ans = 0, flag = 1;
    while (x != y) {
        if (flag) {
            ans += len-x;
            x = len;
        }
        else {
            ans += len-x;
            x = -len;
            len++;
        }
        flag = 1-flag;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "lostcow"
    if (fopen(TASK".in", "r")) {
        freopen(TASK".in", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
