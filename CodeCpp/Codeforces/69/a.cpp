#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    int sx = 0, sy = 0, sz = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        sx += x;
        sy += y;
        sz += z;
    }
    if (sx || sy || sz) cout << "NO";
    else cout << "YES";
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