#include<bits/stdc++.h>
using namespace std;

const int maxN=5*1e4+9;
long long n, x, ans = 0;
long long power[maxN];

int main() {
    freopen("dathuc.inp", "r", stdin);
    freopen("dathuc.out", "w", stdout);
    cin >> x >> n;
    power[n+1]=1;
    for (int i = n; i >= 1; i--) {
        power[i] = power[i+1]*x;
    }
    for (int i = 1; i <= n+1; i++) {
        int a; cin >> a;
        ans += a*power[i];
    }
    cout << ans;
}