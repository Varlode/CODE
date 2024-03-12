#include<bits/stdc++.h>
using namespace std;

const int SIZE = 5e6+10;
int n, m, a[SIZE], mn[SIZE];
long long ans;
vector<int> pos;

void process()
{
    pos.clear();
    pos.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!pos.empty() && a[pos.back()] >= a[i])
            pos.pop_back();
        mn[i] = pos.back();
        pos.push_back(i);
    }
    pos.clear();
    pos.push_back(n+1);
    for (int i = n; i >= 1; i--)
    {
        while (!pos.empty() && a[pos.back()] >= a[i])
            pos.pop_back();
        ans = max(ans, 1ll*a[i]*(pos.back() - mn[i] - 1));
        pos.push_back(i);
    }
}

void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    process();

    for (int i = 1; i <= n; i++)
    {
        a[i] = m - a[i];
    }
    process();

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
