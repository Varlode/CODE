#include<bits/stdc++.h>
using namespace std;

const int SIZE = 4e5+100;
const int SIZE_3 = 1e3+100;
int n, k;
int a[SIZE], b[SIZE];

map<long long, long long> mark_l, mark_r;
long long mx[SIZE];
void solve_sub_1_4()
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        mark_l[b[i]] += a[i];
        ans = max(ans, mark_l[b[i]]);
    }
    cout << ans;
    return;
}

void solve_sub_2_5()
{
    long long res = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        mark_l[b[i]] += (long long) a[i];
        mx[i] = max(mx[i-1], mark_l[b[i]]);
    }
    for (int i = n; i >= 1; i--)
    {
        mark_r[b[i]] += (long long) a[i];
        res = max(res, mark_r[b[i]]);
        ans = max(ans, mx[i-1] + res);
    }
    cout << ans;
    return;
}

long long dp_3[SIZE_3][31];
void solve_sub_3()
{
    for (int i = 1; i <= n; i++)
    {
        dp_3[i][0] = a[i];
        for (int j = 1; j < i; j++)
        {
            if (b[i] != b[j]) for (int l = 0; l < k; l++)
            {
                dp_3[i][l+1] = max(dp_3[i][l+1], dp_3[j][l] + a[i]);
            }
            else for (int l = 0; l <= k; l++)
            {
                dp_3[i][l] = dp_3[j][l]+a[i];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++)
        ans = max(ans, dp_3[i][j]);
    cout << ans;
    return;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = i-a[i];
    }

    if (k == 0)
    {
        solve_sub_1_4();
        return;
    }
    if (k == 1)
    {
        solve_sub_2_5();
        return;
    }
    if (n <= 1000)
    {
        solve_sub_3();
        return;
    }
    return;
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
    // cin >> Test;
    while (Test--)
    {
        solve();
    }
}
