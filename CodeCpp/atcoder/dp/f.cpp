/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 3001;
int dp[N][N];
pair<int, int> trace[N][N];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = "~"+s;
    t = "~"+t;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        if (dp[i][j] == dp[i][j-1]) trace[i][j] = {i, j-1};
        if (dp[i][j] == dp[i-1][j]) trace[i][j] = {i-1, j};
        if (s[i] == t[j]) {
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            if (dp[i][j] == dp[i-1][j-1]+1) trace[i][j] = {i-1, j-1};
        }
    }
    vector<char> ans;
    int x = n, y = m;
    while (true) {
        if (s[x] == t[y]) ans.push_back(s[x]);
        pair<int, int> p = trace[x][y];
        if (p == make_pair(0, 0)) break;
        x = p.first;
        y = p.second;
    }
    reverse(ans.begin(), ans.end());
    for (auto c: ans) cout << c;
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
