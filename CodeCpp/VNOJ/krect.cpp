/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int n, m, S;
int a[N][N], mark[26];

long long calc(int s) {
    cerr << s << '\n';
    long long res = 0;
    for (int i = 1; i <= m; i++) for (int j = i; j <= m; j++) {
        int cnt = 0, l = 1;
        memset(mark, 0, sizeof mark);
        for (int r = 1; r <= n; r++) {
            for (int k = i; k <= j; k++) {
                cnt += (mark[a[k][r]] == 0);
                mark[a[k][r]]++;
            }

            while (l <= r && cnt > s) {
                for (int k = i; k <= j; k++) {
                    mark[a[k][l]]--;
                    cnt -= (mark[a[k][l]] == 0);
                }
                l++;
            }
            res += r - l + 1;
        }
    }
    return res;
}

void solve() {
    cin >> m >> n >> S;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        char c; cin >> c;
        a[i][j] = c-'A';
        cerr << a[i][j] << ' ';
        if (j == n) cerr << '\n';
    }
    cout << calc(S) - calc(S-1);
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
