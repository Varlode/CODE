#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x; cin >> n >> x;
    vector<long long> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int lw = lower_bound(a.begin() + 1, a.end(), a[i] + x) - a.begin();
        int up = upper_bound(a.begin() + 1, a.end(), a[i] + x) - a.begin();
        cout << (long long) a[i - 1] + x << ' ' << lw << ' ' << up << endl;
        ans += up - lw + 1;
    }
    cout << ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}   