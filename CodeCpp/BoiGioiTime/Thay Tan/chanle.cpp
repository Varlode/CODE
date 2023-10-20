#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, p, q;
int a[N], ans = 1e9;

main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("chanle.inp", "r", stdin);
    // freopen("chanle.out", "w", stdout);
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = 1;
    int cntl = 0, cntc = 0;
    while (r <= n) {
        if (a[r]&1) cntl++;
        else cntc++;
        while (cntl >= q && cntc >= p && l <= n) {
            ans = min(ans, r-l+1);
            if (a[l]&1) cntl--;
            else cntc--;
            l++;
        }
        r++;
    }
    cout << (ans == 1e9? -1 : ans);    
}
