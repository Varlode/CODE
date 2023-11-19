#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6;
int n, q, x[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x+1, x+1+n);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int m; cin >> m;
        cout << upper_bound(x+1, x+1+n, m) - x - 1 << endl;
    }
}