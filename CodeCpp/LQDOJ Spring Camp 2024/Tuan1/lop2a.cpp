#include<bits/stdc++.h>
using namespace std;

int a, b, x, y;

void solve() {
    cin >> a >> b >> x >> y;
    long double h1 = (long double) a/x, h2 = (long double) b/y;
    if (abs(h1 - h2) < 0.000000001) cout << "YES";
    else cout << "NO";
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    solve();
}
