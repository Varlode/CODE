#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c; cin >> a >> b >> c;
    cout << 
    max(a + b + c,
    max(a + b * c,
    max(a * b + c,
    max(a * b * c,
    max(a * c + b * c, 
    a * b + a * c)))));
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