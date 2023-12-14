
/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;
int m, n, c[N], l[N];
long long dp[N], ans;
char a[N][N];

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        cin >> a[i][j];

    c[0] = -1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            if (a[i][j] == '1') c[j]++; else c[j] = 0;

        vector<int> v;
        v.push_back(0);
        for (int j = 1; j <= n; j++) {
            while (v.size() && c[v.back()] >= c[j]) v.pop_back();
            l[j] = v.back();
            v.push_back(j);
        }

        for (int j = 1; j <= n; j++) {
            dp[j] = (j - l[j]) * c[j] + dp[l[j]];
            ans += dp[j];
        }
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
