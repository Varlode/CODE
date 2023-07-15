#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++)
    {
        int f, s; cin >> f >> s;
        a[i] = make_pair(f, s);
    }
    sort(a.begin(), a.end(), greater< pair<int, int> >());
    int pre = 0, i = 0;
    long long ans = 0;
    while (i < n)
    {
        int cnt = 0;
        if (a[i].first != pre) {
            pre = a[i].first;
            while (i < n && a[i].first == pre && cnt < pre)
            {
                ans += a[i].second;
                i++; cnt++;
            }
        } else i++;
    }
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