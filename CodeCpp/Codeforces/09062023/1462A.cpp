#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; 

    cin >> n;
    vector<int> a(n), ans(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int curr1 = 0, curr2 = n - 1, cnt = 0;
    while (curr1 < curr2)
    {
        ans[cnt++] = a[curr1++];
        ans[cnt++] = a[curr2--];
    }
    if (curr1 == curr2) ans[cnt++] = a[curr1];
    cout << ans[0];
    for (int i = 1; i < n; i++)
        cout << " " << ans[i];
    cout << endl;
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