#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n, m, k;

long long calc(int mid)
{
    long long result = 0;
    int l = max(0, (mid-1) - (k-1));
    int r = max(0, (mid-1) - (n-k));
    result = -1ll*l*(l+1)/2 + 1ll*mid*mid  + -1ll*r*(r+1)/2;
    return result;
}

void solve()
{
    cin >> n >> m >> k;

    int l = 1, r = 1e9, ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (calc(mid) <= m)
        {
            ans = m-mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << '\n' ;
}

int main()
{
    #define task "TASK"
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
