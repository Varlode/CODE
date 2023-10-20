#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, ans = 0;
    while (i < j - 1) {
        int x = m - a[i] - a[j];
        // cout << " a[i]: " << a[i] << " x: " << x << " a[j]: " << a[j] << endl;
        int tmp = upper_bound(a.begin() + i, a.begin() + j, x) - a.begin() - 1;
        // cout << " i: " << i << " tmp: " << tmp << " j: " << j << endl;
        if (i < tmp && tmp < j) {
            ans = max(ans, a[i] + a[tmp] + a[j]);
            i++;
            // cout << " a[i]: " << a[i] << " a[tmp]: " << a[tmp] << " a[j]: " << a[j] << endl;
        } else j--;
    }
    cout << ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}   