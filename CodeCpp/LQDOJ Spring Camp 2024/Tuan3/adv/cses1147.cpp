#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e3+10;
int n, m, a[SIZE], L[SIZE], R[SIZE];
long long ans;
vector<int> f;

void solve()
{
    cin >> m >> n;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            char x; cin >> x;
            if (x == '.') a[i]++;
            else a[i] = 0;
        }
        f.clear();
        for (int i = 1; i <= n; i++)
        {
            while (!f.empty() && a[f.back()] >= a[i])
                f.pop_back();
            L[i] = f.empty()? 0: f.back();
            f.push_back(i);
        }
        f.clear();
        for (int i = n; i >= 1; i--)
        {
            while (!f.empty() && a[f.back()] >= a[i])
                f.pop_back();
            R[i] = f.empty()? n+1: f.back();
            f.push_back(i);
        }
        long long res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, (R[i] - L[i] - 1) * 1ll * a[i]);
        ans = max(ans, res);
    }
    cout << ans;
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

