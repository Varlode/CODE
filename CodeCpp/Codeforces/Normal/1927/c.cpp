#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N], b[N], A[N], B[N];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) A[i] = B[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int ok = 0;
    for (int i = 1; i <= n; i++) if (a[i] <= k) {
        ok += A[a[i]] == 0 && B[a[i]] == 0;
        A[a[i]]++;
    }
    for (int i = 1; i <= m; i++) if (b[i] <= k) {
        ok += A[b[i]] == 0 && B[b[i]] == 0;
        B[b[i]]++;
    }
    if (ok != k) {
        cout << "no\n";
        return;
    }
    ok = 0;
    for (int i = 1; i <= k; i++) {
        if (B[i] == 0) ok++;
    }
    if (ok > k/2) {
        cout << "no\n";
        return;
    }

    ok = 0;
    for (int i = 1; i <= k; i++) {
        if (A[i] == 0) ok++;
    }
    if (ok > k/2) {
        cout << "no\n";
        return;
    }
    cout << "yes\n";
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
