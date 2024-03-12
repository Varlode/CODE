#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, p, h;

long long ans;

void solve() {
    cin >> n >> p >> h;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '#') continue;
        if (c == 'M') {
            if (h > 1) {
                h--;
                continue;
            }
            if (p == 1) {
                cout << -1;
                return;
            }
            p--;
            ans++;
        }
        if (c == 'P') p++;
        if (c == 'H') h++;
    }
    cout << ans;
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    solve();
}
