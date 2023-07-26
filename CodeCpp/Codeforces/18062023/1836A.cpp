#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), cnt(102, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] > cnt[a[i] - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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