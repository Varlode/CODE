#include<bits/stdc++.h>
using namespace std;

int n, m, ans = 0;

int main() {
    freopen("sontuong.inp", "r", stdin);
    freopen("sontuong.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ans += m-a;
    }
    cout << ans;
}