#include<bits/stdc++.h>
using namespace std;

void solve()
{
    unsigned long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d * c - b == 0 || c == 0) {
        cout << -1;
        return;
    }
    cout << (unsigned long long) ceil((long double) a / (d * c - b));
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