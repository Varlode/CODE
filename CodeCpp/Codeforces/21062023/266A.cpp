#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1]) ans++;
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