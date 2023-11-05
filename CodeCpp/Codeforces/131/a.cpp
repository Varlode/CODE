#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    bool ok1 = false, ok2 = true, ok3 = false;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == char(tolower(s[i]))) {
            ok2 = false;
            break;
        }
    ok3 = char(tolower(s[0])) == s[0];
    ok1 = ok2 & ok3;
    if (ok1) {
        for (int i = 0; i < s.size(); i++)
            s[i] = char(tolower(s[i]));
        s[0] = char(toupper(s[0]));
    }
    cout << s;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}