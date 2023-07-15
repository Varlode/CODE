#include<bits/stdc++.h>
using namespace std;

int cntp, cntn;

void solve()
{
    string n; int k;
    cin >> n >> k;
    while (k--) {
        if (n.back() == '0')
            n.pop_back();
        else
            n.back() -= 1;
    }
    cout << n;
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