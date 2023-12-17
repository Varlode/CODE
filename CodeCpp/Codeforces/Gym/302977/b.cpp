/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int n, k, mark[26];
char a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        char c; cin >> c;
        mark[c-'a'] = 1;
    }
    long long ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mark[a[i]-'a']) cnt++;
        else {
            ans += 1ll*cnt*(cnt+1)/2;
            cnt = 0;
        }
    }
    ans += 1ll*cnt*(cnt+1)/2;
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
