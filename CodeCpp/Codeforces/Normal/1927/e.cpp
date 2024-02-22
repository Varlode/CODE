#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
const int inf = 1e9;
int a[N], n, k;

void solve() {
    cin >> n >> k;
    int l = 1, r = k;
    int curL = 1, curR = n, flag = 0;
    while (l < r) {
        if (flag == 0) {
            for (int i = 1; l+(i-1)*k <= n; i++)
                a[l+(i-1)*k] = curL++;
            for (int i = 1; r+(i-1)*k <= n; i++)
                a[r+(i-1)*k] = curR--;
        }
        else {
            for (int i = 1; l+(i-1)*k <= n; i++)
                a[l+(i-1)*k] = curR--;
            for (int i = 1; r+(i-1)*k <= n; i++)
                a[r+(i-1)*k] = curL++;
        }
        flag = 1-flag;
        l++; r--;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
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
