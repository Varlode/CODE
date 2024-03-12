#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6+1;
int n, k, a[N];

bool check(int m) {
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cnt += (a[i+1] - a[i]) / (m-1);
        if ((a[i+1] - a[i]) % (m-1) == 0) cnt--;
        if (cnt > k) return true;
    }
    return false;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int l = 2, r = 2e9+10, ans = 1;
    while (l <= r)
    {
        int m = (r + l) >> 1;
        if (check(m))
        {
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }
    cout << ans;
}

main()
{
    #define task "TASK"
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
//    cin >> t;
    while (t--)
    {
        solve();
    }
}
