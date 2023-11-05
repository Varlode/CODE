#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), neg(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) neg[i] = 1;
        else if (a[i] == 0 && neg[i - 1]) neg[i] = 1;
    }
    unsigned long long ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i]);
        if (neg[i - 1] == 0 && neg[i] == 1) cnt++;
    }
    cout << ans << ' ' << cnt << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}