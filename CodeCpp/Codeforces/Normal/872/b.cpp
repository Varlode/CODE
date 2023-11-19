#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, k, a[N];
int f[N], g[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    if (k == 1) {
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) ans = min(ans, a[i]);
        cout << ans;
        return 0;
    }

    if (k >= 3) {
        int ans = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
        cout << ans << endl;
        return 0;
    }

    f[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        f[i] = min(a[i], f[i-1]);
    }
    
    g[n+1] = 0x3f3f3f3f;
    for (int i = n; i >= 1; i--) {
        g[i] = min(a[i], g[i+1]);
    }

    int ans = -0x3f3f3f3f;
    for (int i = 1; i < n; i++)
        ans = max(ans, max(f[i], g[i+1]));
    cout << ans;

}