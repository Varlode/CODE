#include<bits/stdc++.h>
using namespace std;

long long incl, incr;

void solve()
{
    long long n; cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    long long ans = 1e16;
    int l = 1, r = 1;
    while (l <= n && r <= n && l <= r) {
        ans = min(ans, abs(a[n] - 2*(a[r] - a[l - 1])));
        if (r == n) {
            l++;
            continue;
        }
        incl = abs(a[n] - 2*(a[r] - a[l]));
        incr = abs(a[n] - 2*(a[r + 1] - a[l - 1]));
        if (incr <= incl) r++;
        else l++;
    }
    cout << ans << endl;
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