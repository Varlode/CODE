#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
const int MOD = 1e9+7;
int n, k;
int a[N], dp[N], l[N], r[N];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}

void sub(int &a, int b)
{
    a += MOD - b;
    if (a >= MOD) a -= MOD;
}

void solve_sub_1_2()
{
    if (k == 2)
    {
        int l_giao = max(l[1], l[2]);
        int r_giao = min(r[1], r[2]);
        if (r_giao >= l_giao)
        {
            l[1] = min(l[1], l[2]);
            r[1] = max(r[1], r[2]);
            k--;
        }
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int u = 1; u <= k; u++)
            for (int j = max(0, i-r[u]); j <= max(0, i-l[u]); j++)
                add(dp[i], dp[j]);
    }
    cout << dp[n];
}

void solve_sub_3()
{
    int cur = 0;
    for (int i = 1; i <= k; i++)
    {
        if (l[i] == 0 && r[i] == 0) continue;
        for (int j = i+1; j <= k; j++)
        {
            if (l[j] == 0 && r[j] == 0) continue;
            int l_giao = max(l[i], l[j]);
            int r_giao = min(r[i], r[j]);
            if (r_giao >= l_giao)
            {
                l[i] = min(l[i], l[j]);
                r[i] = max(r[i], r[j]);
                l[j] = 0;
                r[j] = 0;
            }
        }
        ++cur;
        l[cur] = l[i];
        r[cur] = r[i];
    }

    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int u = 1; u <= cur; u++)
            for (int j = max(0, i-r[u]); j <= max(0, i-l[u]); j++)
                add(dp[i], dp[j]);
    }
    cout << dp[n];
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> l[i] >> r[i];

    if (n <= 5000 && k <= 2)
    {
        solve_sub_1_2();
        return;
    }
    if (n <= 5000)
    {
        solve_sub_3();
        return;
    }
}

int main()
{
    #define task "TASK"
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int Test = 1;
//    cin >> Test;
    while (Test--)
    {
        solve();
    }
}
