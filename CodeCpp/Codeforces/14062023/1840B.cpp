#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    k = min(k, 30);
    cout << min(n + 1, 1 << k) << endl;
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