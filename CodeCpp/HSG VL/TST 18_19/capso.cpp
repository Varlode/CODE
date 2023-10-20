#include<bits/stdc++.h>
using namespace std;

int n, a;
long long ans = 0;
map<int, int> m;

int main() {
    freopen("capso.inp", "r", stdin);
    freopen("capso.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <=n; i++) {
        cin >> a;
        ans += m[-a];
        m[a]++;
    }
    cout << ans;
}