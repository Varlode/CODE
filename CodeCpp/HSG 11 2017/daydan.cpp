#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+9;
int n, m, ans = 0;
int a[maxN];

bool check(int x, int sum = 0) {
    for (int i = n; i >= 1; i--) {
        sum += a[i]/x;
        if (sum >= m) break;
    }
    return sum >= m;
}

int main () {
    freopen("daydan.inp", "r", stdin);
    freopen("daydan.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a+n+1);
    int l = 1, r = a[n];
    while (l <= r) {
        int mi = l + (r-l)/2;
        if (check(mi)) {
            l = mi + 1;
            ans = mi;
        } else {
            r = mi - 1;
        }
    }
    cout << ans;
}