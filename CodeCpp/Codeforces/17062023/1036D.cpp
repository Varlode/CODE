#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m; cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    long long i = 1, j = 1, s1 = a[0], s2 = b[0], ans = 0;
    while (i < n && j < m)
    {
        if (s1 == s2) {
            s1 = a[i++];
            s2 = b[j++];
            ans++;
            continue;
        }
        if (s1 < s2)
            s1 += a[i++];
        else
            s2 += b[j++];
    }
    while (i < n) {
        s1 += a[i];
        i++;
    }
    while (j < m) {
        s2 += b[j];
        j++;
    }
    if (s1 == s2) cout << ans + 1;
    else cout << -1;
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