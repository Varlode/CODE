#include<bits/stdc++.h>
using namespace std;

const int maxN = 5*10000+9;
int n, m;
long long min_val, ans;
long long a[maxN];

int main() {
    freopen("diemso.inp", "r", stdin);
    freopen("diemso.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        min_val = a[x-1]; ans = a[x]-a[x-1];
        for (int i = x; i <= y; i++) {
            ans = max(ans, a[i] - min_val);
            min_val = min(min_val, a[i]);
        }
        cout << ans << endl;
    }
}