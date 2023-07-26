#include<bits/stdc++.h>
using namespace std;

int a[200009];

void solve()
{
    int n, k, q; cin >> n >> k >> q;
    int ma = -1e9, mi = 1e9;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        mi = min(mi, x);
        ma = max(ma, y);
        a[x] += 1; a[y + 1] -= 1;
    }
    for (int i = mi; i <= ma + 1; i++)
        a[i] += a[i - 1];
    for (int i = mi; i <= ma + 1; i++) {
        if (a[i] >= k) a[i] = 1;
        else a[i] = 0;
    }
    for (int i = mi; i <= 200000; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        cout << a[y] - a[x - 1] << endl;
    }
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