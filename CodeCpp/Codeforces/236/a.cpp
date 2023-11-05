#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    set<int> a;
    for (int i = 0; i < s.size(); i++)
        a.insert(int(s[i]));
    if (a.size() & 1) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
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