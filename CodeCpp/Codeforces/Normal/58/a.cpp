#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    string pre = "hello";
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == pre[cnt]) cnt++;
    if (cnt == 5) cout << "YES";
    else cout << "NO";
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