#include <bits/stdc++.h>
using namespace std;

void solve(void) {
    int n; cin >> n;
    int cnt[2]; cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a; a--;
        cnt[a]++;
    }
    if (cnt[0]&1) {cout << "NO\n"; return;}
    if (cnt[0]==0 && cnt[1]&1) {cout << "NO\n"; return;}
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int nt; cin >> nt;
    while (nt--) solve();
}