#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long k, n, w; cin >> k >> n >> w;
    if (w * (w + 1) / 2 * k > n) cout << w * (w + 1) / 2 * k - n;
    else cout << 0;
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