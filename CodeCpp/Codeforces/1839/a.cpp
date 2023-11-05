#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) cnt1++;
        int ceil = (i + 1) / k;
        if ((i + 1) % k != 0) ceil++;
        if (ceil > cnt1) {
            a[i] = 1;
            cnt1++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) cnt2++;
        int ceil = (n - i) / k;
        if ((n - i) % k != 0) ceil++;
        if (ceil > cnt2) {
            a[i] = 1;
            cnt2++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1) ans++;
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