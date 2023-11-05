#include <bits/stdc++.h>
using namespace std;

long long m, n, k;
long long ans;
long long x[100100], y[100100];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("camping.inp", "r", stdin);
    freopen("camping.out", "w", stdout);
    cin >> m >> n >> k;
    ans = (m-1)*n + (n-1)*m;
    set<pair<long long, long long>> s;
    for (int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i];
    }   
    for (int i = 1; i <= k; i++) {
        if (x[i]-1>=1 && s.find({x[i]-1, y[i]}) == s.end()) ans--;
        if (y[i]-1>=1 && s.find({x[i], y[i]-1}) == s.end()) ans--;
        if (x[i]+1<=m && s.find({x[i]+1, y[i]}) == s.end()) ans--;
        if (y[i]+1<=n && s.find({x[i], y[i]+1}) == s.end()) ans--;
        s.insert({x[i], y[i]});
    }
    cout << ans;
}