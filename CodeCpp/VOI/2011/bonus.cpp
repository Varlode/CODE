/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n, k, ans;
int a[N][N];

int calc(int x, int y) {
    return a[x][y] - a[x-k][y] - a[x][y-k] + a[x-k][y-k];
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
    for (int i = k; i <= n; i++) for (int j = k; j <= n; j++)
        ans = max(ans, calc(i, j));
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
