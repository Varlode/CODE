#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        int x, y, k; cin >> x >> y >> k;
        if (x >= y) cout << x << '\n';
        else {
            if (x+k >= y) cout << y << '\n';
            else cout << y+(y-x-k) << '\n';
        }
    }
}