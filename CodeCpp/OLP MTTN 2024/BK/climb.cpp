#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, q;
int a[N], b[N];

void solve_sub_1()
{
    for (int i = 1; i <= q; i++)
    {
        long long x; cin >> x;
        long long res = 0;
        for (int i = 1; i <= q; i++)
        {
            if (x < a[i]) break;
            res += a[i];
            x -= b[i];
        }
        cout << res << '\n';
    }
}


long long pref_sub_2[N];
void solve_sub_2()
{
    vector<pair<int, int>> acs;
    acs.push_back({0, 0});
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > acs.back().first)
            acs.push_back({a[i], i});
        if (a[i] == acs.back().first)
        {
            acs.pop_back();
            acs.push_back({a[i], i});
        }
    }
    acs.back().second = n;
    for (int i = 1; i <= n; i++) pref_sub_2[i] = pref_sub_2[i-1]+a[i];
    for (int i = 1; i <= q; i++)
    {
        long long x; cin >> x;
        int l = 1, r = acs.size()-1, res = 0;
        while (l <= r)
        {
            int m = (l+r) >> 1;
            if (acs[m].first <= x)
            {
                res = m;
                l = m+1;
            }
            else r = m-1;
        }
        cout << pref_sub_2[acs[res].second] << '\n';
    }
}

long long pref_sub_3[N];
void solve_sub_3()
{
    vector<pair<int, int>> acs;
    acs.push_back({0, 0});
    for (int i = 1; i <= n; i++)
    {
        if (a[i]+b[i] >= acs.back().first)
            acs.push_back({a[i], i});
    }
    for (int i = 1; i <= n; i++) pref_sub_2[i] = pref_sub_2[i-1]+a[i];
    for (int i = 1; i <= n; i++) pref_sub_3[i] = pref_sub_3[i-1]+b[i];
    for (int i = 1; i <= q; i++)
    {
        long long x; cin >> x;
        int l = 1, r = acs.size()-1, res = 0;
        while (l <= r)
        {
            int m = (l+r) >> 1;
            if (acs[m].first <= x-pref_sub_3[acs[m].second])
            {
                res = m;
                l = m+1;
            }
            else r = m-1;
        }
        if (res == acs.size()-1) cout << pref_sub_2[n] << "\n";
        else cout << pref_sub_2[acs[res].second] << "\n";
    }
}

int sub_2, sub_3;
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sub_2 += b[i] == 0;
        sub_3 += b[i] < 0;
    }
    if (n <= 2000 && q <= 2000)
    {
        solve_sub_1();
        return;
    }

    if (sub_2 == n)
    {
        solve_sub_2();
        return;
    }

    if (sub_3 == n)
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
