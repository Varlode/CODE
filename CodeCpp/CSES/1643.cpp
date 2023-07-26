#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    long long s = 0, mis = 0, ans = -1e9;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s += x;
        ans = max(ans, s - mis);
        mis = min(mis, s);
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