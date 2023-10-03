#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, t; 

    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int curr1 = 0, curr2 = 0, cnt = 0, time_read = 0, ans = 0;
    while (curr2 < n && curr1 < n)
    {
        if (time_read + a[curr2] <= t)
        {
            time_read += a[curr2];
            cnt++; curr2++;
            ans = max(ans, cnt);
        }
        else if (cnt > 0)
        {
            time_read -= a[curr1];
            curr1++; cnt--;
        }
        else curr2++;
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