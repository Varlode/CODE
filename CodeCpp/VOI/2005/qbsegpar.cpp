#include<bits/stdc++.h>
using namespace std;

const int N = 20000;
const int limit = 500000000;
int n, k;
int a[N], f[N], g[N];

void reset(int m) {
    for (int i = 1; i <= n; i++) {
        f[i] = n+10;
        g[i] = 0;
    }
}

void update(int u) {
    int idx = u;
    
}

bool check(int m) {
    reset(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) 
            if (a[i]-m <= a[j])
                f[i] = min(f[i], f[j] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            if (a[i]-m <= a[j])
                g[i] = max(g[i], g[j] + 1);
    }
    return (f[n] <= k && k <= g[n]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = 1e9;
    int l = -limit, r = limit;
    while (l <= r) {
        int m = l+(r-l)/2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else 
            l = m + 1;
    }
    cout << ans;
}