#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (i == 0) 
                s[i] = '0';
            else if (s[i - 1] == '1' || s[i + 1] == '1')
                s[i] = '1';
            else
                s[i] = '0';
        }
    }
    cout << s << endl;
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