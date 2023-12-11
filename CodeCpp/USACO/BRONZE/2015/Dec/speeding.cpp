/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1010101;
int n, m;
pair<int, int> a[N], b[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    int len = 0, ans = 0;
    int curr1 = 1, curr2 = 1;
    while (len < 100) {

        ans = max(ans, b[curr2].second-a[curr1].second);
        if (a[curr1].first == b[curr2].first) {
            len += a[curr1].first;
            curr1++; curr2++;
            continue;
        }
        if (a[curr1].first > b[curr2].first) {
            len += b[curr2].first;
            a[curr1].first -= b[curr2].first;
            curr2++;
            continue;
        }
        if (a[curr1].first < b[curr2].first) {
            len += a[curr1].first;
            b[curr2].first -= a[curr1].first;
            curr1++;
            continue;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "speeding"
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
