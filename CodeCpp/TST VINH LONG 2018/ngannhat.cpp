#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+9;
int n, m, x, y, z, cntx = 0, cnty = 0, ans = 1e9, limit = 0;
int a[maxN], b[maxN];


int main() {
    freopen("ngannhat.inp", "r", stdin);
    freopen("ngannhat.out", "w", stdout);
    cin >> n >> m;
    cin >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> z;
        a[z] = 1;
        limit = max(limit, z);
    }
    for (int i = 1; i <= m; i++) {
        cin >> z;
        b[z] = 1;
        limit = max(limit, z);
    }
    int l = 1, r = 1;
    while (r <= limit) {
        while (r <= limit && (cntx < x || cnty < y)) {
            cntx += a[r];
            cnty += b[r];
            r++;
        }
        while (l <= r && (cntx > x && cnty > y)) {
            cntx -= a[l];
            cnty -= b[l];
            l++;
        }
        if (cntx >= x && cnty >= y) ans = min(ans, r-l-1);

        cntx -= a[l];
        cnty -= b[l];
        l++;
    }
    if (ans == 1e9) cout << -1; else cout << ans;
}