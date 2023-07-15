#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n - 1, s = 0, d = 0, ok = 1;
    while (l <= r)
    {
        if (a[l] < a[r]) 
        {
            if (ok) s += a[r];
            else d += a[r];
            r--;
        }
        else
        {
            if (ok) s += a[l];
            else d += a[l];
            l++;
        }
        ok = !ok;
    }
    cout << s << " " << d;
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