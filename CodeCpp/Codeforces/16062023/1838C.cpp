#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (i & 1) {
                cout << (n / 2 + i / 2) * m + j << ' ';
            } else {
                cout << (i / 2 - 1) * m + j << ' ';
            }
        cout << endl;
    }
    cout << endl;
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