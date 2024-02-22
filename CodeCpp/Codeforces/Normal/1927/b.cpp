#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int cnt[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cout << char(cnt[x]+'a');
        cnt[x]++;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
