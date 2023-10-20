#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+9;
int n, x, s = 0, ans = -1;
map<int, int> m;

int main() {
    freopen("loinhuan.inp", "r", stdin);
    freopen("loinhuan.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s += x;
        if (m[s] == 0) m[s] = i;
        else ans = max(ans, i-m[s]);
        if (s == 0) ans = i;
    }
    cout << ans;
}