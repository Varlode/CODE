/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int val[N][N];
long long cheoChinh[N], cheoPhu[N], hang[N], cot[N];
int k;

void solve() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int x, y, w; cin >> x >> y >> w;
        val[x][y] = w;
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cheoChinh[8-i+j] += val[i][j];
            cheoPhu[i+j-1] += val[i][j];
            hang[i] += val[i][j];
            cot[j] += val[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) {
        if (val[i][j]) continue;
        ans = max(ans, cheoChinh[8-i+j]+cheoPhu[i+j-1]+hang[i]+cot[j]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "quanhau"
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
