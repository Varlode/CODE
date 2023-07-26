#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, w, h; cin >> n >> w >> h;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int maxRight = -1e9, maxLeft = 1e9;
    for (int i = 0; i < n; i++)
    {
        maxRight = max(maxRight, (b[i] + h) - (a[i] + w));
        maxLeft = min(maxLeft, (b[i] - h) - (a[i] - w));
    }
    if (maxRight > maxLeft) cout << "NO" << endl;
    else cout << "YES" << endl;
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