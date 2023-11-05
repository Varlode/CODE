#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), res(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int pre = 0, flag = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= pre && flag == 1) {
            pre = a[i];
            res[i] = 1;
        } else 
        if (a[i] < pre && a[i] > a[1] && flag == 1) {
            res[i] = 0;
        } else
        if (a[i] < pre && a[i] <= a[1] && flag == 1) {
            flag = 0;
            pre = a[i];
            res[i] = 1;
        } else
        if (flag == 0 && pre <= a[i] && a[i] <= a[1]) {
            pre = a[i];
            res[i] = 1;
        } else
            res[i] = 0;

    }
    for (int i = 1; i <= n; i++)
        cout << res[i];
    cout << endl;
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