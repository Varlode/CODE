#include <bits/stdc++.h>
using namespace std;

int n, a[100100], ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[i-1]) cnt++;
        else cnt = 1;
        ans = max(ans, cnt);
    }
    cout << ans;
}