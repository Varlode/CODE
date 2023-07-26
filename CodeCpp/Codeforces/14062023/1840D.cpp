#include<bits/stdc++.h>
using namespace std;

int a[200010], ans = 1e9 + 7, n, t;

bool check(int m) {
    int i = 1; 
    while (i <= n && a[i] - a[1] <= m + m) i++;
    int j = n;
    while (j >= 1 && a[n] - a[j] <= m + m) j--;
    if (i > j || a[j] - a[i] <= m + m)
        return true;
    return false;
}

void bi_se(int l, int r) {
    if (r < l) return;
    int m = l + (r - l) / 2;
    if (check(m)) {
        ans = m;
        bi_se(l, m - 1);
    } else
        bi_se(m + 1, r);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = -1e9 - 7, a[n + 1] = 1e9 + 7;
    sort(a + 1, a + n + 1);
    bi_se(0, (a[n] - a[1]) / 6 + (a[n] - a[1]) % 6);
    cout << ans << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
        solve();
}   