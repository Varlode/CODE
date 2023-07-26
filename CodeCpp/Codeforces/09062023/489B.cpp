#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m; 

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m ; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    int curr1 = 0, curr2 = 0, ans = 0;
    while (curr1 < n && curr2 < m)
    {
        if (abs(a[curr1] - b[curr2]) <= 1)
        {
            ans++;
            curr1++;
            curr2++;
        }
        else if (a[curr1] > b[curr2]) curr2++;
        else curr1++;
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