#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+9;
int n, m, a[maxN], ans;

bool check(int x) {
    int pre = a[1], cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i]-pre >= x) {
            pre=a[i];
            cnt++;
        }
        if (cnt >= m) break;
    }
    return cnt >= m;
}

int main() {
    freopen("traibo.inp", "r", stdin);
    freopen("traibo.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        sort(a, a+n+1);
        int l = 1, r = a[n]-a[1];
        while (l <= r) {
            int m = l+(r-l)/2;
            if (check(m)) {
                ans = m; 
                l = m+1;
            } else {
                r = m-1;
            }
        }
        cout << ans << endl;
    }
}