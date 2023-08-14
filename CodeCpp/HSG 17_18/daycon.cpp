#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4+9;
int n, k, a[maxN], ans = 0;
map<int, int> m;

int main() {
    freopen("daycon.inp", "r", stdin);
    freopen("daycon.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
        a[i] %= k;
        if (m[a[i]] == 0) m[a[i]] = i;
        else {
            ans = max(ans, i - m[a[i]]);
            if (a[i] == 0) ans = i;
        }
    }
    cout << ans;
}