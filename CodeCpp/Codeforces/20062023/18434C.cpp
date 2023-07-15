#include<bits/stdc++.h>
using namespace std;

void solve()
{
    unsigned long long n; cin >> n;
    unsigned long long ans = 0;
    while (n > 1) {
        ans += n;
        n >>= 1;
    }
    cout << ans + 1 << endl;
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