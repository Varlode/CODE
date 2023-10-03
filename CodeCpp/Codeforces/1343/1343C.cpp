#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; 

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int curr1 = 0, curr2, m; long long ans = 0;
    while (curr1 < n)
    {
        curr2 = curr1;
        m = -1e9;
        while (curr2 < n && a[curr1] > 0 == a[curr2] > 0) 
        {
            m = max(m, a[curr2]);
            curr2++;
        }
        ans += m;
        curr1 = curr2;
    }
    cout << ans << endl;
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