#include<bits/stdc++.h>
using namespace std;

int cntOp, cntCl, cntQu;
string s;

void solve()
{
    cin >> s;
    cntOp = 0; cntCl = 0; cntQu = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') cntOp++;
        if (s[i] == ')') cntCl++;
        if (s[i] == '?') cntQu++;
        if (cntOp + cntQu < cntCl) {
            cout << "NO" << endl;
            return;
        }
    }
    if ((abs(cntOp - cntCl) + cntQu) % 2 == 0)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}   