
/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define sqr(a) (a)*(a)

const int N = 1e3+1;
int m, n, c[N], l[N], r[N], ans;
int a[N][N];
void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        cin >> a[i][j];

    memset(c, 0, sizeof c);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1) c[j]++; else c[j] = 0;

        vector<int> v;
        v.push_back(0);
        for (int j = 1; j <= n; j++) {
            while (v.size() && c[v.back()] >= c[j]) v.pop_back();
            l[j] = v.back();
            v.push_back(j);
        }

        v.clear();
        v.push_back(n+1);
        for (int j = n; j >= 1; j--) {
            while (v.size() && c[v.back()] >= c[j]) v.pop_back();
            r[j] = v.back();
            v.push_back(j);
        }

        for (int j = 1; j <= n; j++) {
            ans = max(ans, min((r[j]-l[j]-1), c[j]));
        }
    }

    memset(c, 0, sizeof 0);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0) c[j]++; else c[j] = 0;

        vector<int> v;
        v.push_back(0);
        for (int j = 1; j <= n; j++) {
            while (v.size() && c[v.back()] >= c[j]) v.pop_back();
            l[j] = v.back();
            v.push_back(j);
        }

        v.clear();
        v.push_back(n+1);
        for (int j = n; j >= 1; j--) {
            while (v.size() && c[v.back()] >= c[j]) v.pop_back();
            r[j] = v.back();
            v.push_back(j);
        }

        for (int j = 1; j <= n; j++) {
            ans = max(ans, min((r[j]-l[j]-1), c[j]));
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
