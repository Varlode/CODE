/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 1010, M = 1010;
pair<long long, int> a[M];

int n, m, k;
int cnt[N];

void solve() {
    cin >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> n >> a[i].se;

        vector<int> x(n+1, 0), y(n+1, 0);

        for (int j = 0; j < n; j++)
            cin >> x[j] >> y[j];
        x[n] = x[0]; y[n] = y[0];

        long long sum = 0;
        for (int j = 0; j < n; j++)
            sum += 1ll*x[j]*y[j+1]-1ll*y[j]*x[j+1];

        a[i].fi = sum;
    }

    sort(a+1, a+1+m);

    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) cnt[j] = 0;

        int mx = 0;
        for (int j = i; j <= m; j++) {
            cnt[a[j].se]++;
            if (cnt[a[j].se] > mx) {
                mx = cnt[a[j].se];
            }
            if (j-i+1-mx <= k) {
                ans = max(ans, a[j].fi-a[i-1].fi);
            }
        }
    }
    cout << fixed << setprecision(1) << ans/2;
    if (ans&1) cout << ".5"; else cout << ".0";
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
