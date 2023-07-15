#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    char tmp;
    int i = 0; 
    while (i < n)
    {
        tmp = s[i];
        i++;
        while (i < n && s[i] != tmp) i++;
        if (i < n && s[i] == tmp) cout << s[i];
        i++;
    }
    cout << endl;
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