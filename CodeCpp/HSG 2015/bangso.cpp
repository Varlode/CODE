#include<bits/stdc++.h>
using namespace std;

int n, pre_sum = 0, a, sum, ans = -1e9-9;

int main() {
    freopen("bangso.inp", "r", stdin);
    freopen("bangso.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum += a;
        ans = max(ans, sum - pre_sum);
        pre_sum = min(pre_sum, sum);
    }
    cout << ans;
}