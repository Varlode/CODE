#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<long long> a(n);
    long long s = 0, div3 = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s += x;
        a[i] = s;
    }
    if ((s % 3 != 0 && s != 0) || n < 3)
    {
        cout << 0 << endl;
        return;
    }
    s /= 3;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == s * 2) ans += div3;
        if (a[i] == s) div3++;
    }
    cout << ans << endl;
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