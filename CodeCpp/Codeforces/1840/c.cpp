#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, q; cin >> n >> k >> q;
    long long cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x <= q) cnt++;
        else {
            if (cnt >= k) ans += (cnt-k+1)*(cnt-k+1 + 1)/2;
            cnt = 0;
        }
    }
    if (cnt >= k) ans += (cnt-k+1)*(cnt-k+1 + 1)/2;
    cout << ans << endl;
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