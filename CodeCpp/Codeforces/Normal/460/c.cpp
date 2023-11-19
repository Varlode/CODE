#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, m, w, a[N];
long long ans = -1, f[N];

int check(int x) {
    long long cnt = 0;    
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] += f[i-1];
        if (a[i] + f[i] < x) {
            long long k = x - a[i] - f[i];
            f[i] += k; 
            f[i+w] -= k;
            cnt += k;
        }
    }
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> w;
    int limit = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        limit = max(limit, a[i]);
    }
    long long l = 1, r = limit+m;
    while (l <= r) {
        long long mid = l+(r-l)/2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}