#include<bits/stdc++.h>
using namespace std;

int cntp, cntn;

void solve()
{
    string n; cin >> n;
    int cntlw = 0, cntup = 0;
    for (int i = 0; i < n.size(); i++) 
        if ('a' <= n[i] && n[i] <= 'z') cntlw++;
        else cntup++;
    if (cntlw >= cntup) {
        for (int i = 0; i < n.size(); i++)
            cout << (char) tolower(n[i]);
    } else {
        for (int i = 0; i < n.size(); i++)
            cout << (char) toupper(n[i]);
    }
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