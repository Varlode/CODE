#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    int mi = 1e9 + 7, ma = -1e9 - 7;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mi = min(mi, x);
        ma = max(ma, x);
    }
    if (mi < 0) cout << mi << endl;
    else cout << ma << endl;
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