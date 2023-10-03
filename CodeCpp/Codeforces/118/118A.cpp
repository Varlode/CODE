#include<bits/stdc++.h>
using namespace std;

bool check(char c)
{
    if (c == 'a' || c == 'A') return false;
    if (c == 'o' || c == 'O') return false;
    if (c == 'y' || c == 'Y') return false;
    if (c == 'e' || c == 'E') return false;
    if (c == 'u' || c == 'U') return false;
    if (c == 'i' || c == 'I') return false;
    return true;
}

void solve()
{
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (check(s[i])) cout << "." << char(tolower(s[i]));
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