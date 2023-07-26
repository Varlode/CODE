#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    if (s.size() & 1) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
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