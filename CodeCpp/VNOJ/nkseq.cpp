#include<bits/stdc++.h>
using namespace std;

int a[200009], mir[200009], mil[200009];

void solve()
{
    int n; cin >> n;
    mil[0] = 1e9; mir[n + 1] = 1e9;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = n; i >= 1; i--) mir[i] = min(a[i], mir[i + 1]);
    for (int i = 1; i <= n; i++) mil[i] = min(a[i], mil[i - 1]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (mir[i] > a[i - 1] && mil[i - 1] > -(a[n] - a[i - 1])) ans++;
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