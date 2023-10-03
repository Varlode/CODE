#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n % k != 0) {
        cout << 1 << endl << n << endl;
        return;
    }
    cout << 2 << endl << k - 1 << ' ' << n - k + 1 << endl;
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