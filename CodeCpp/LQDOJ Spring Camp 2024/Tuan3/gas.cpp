#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
int n, k, sum;
long long ans;
deque<pair<int, int>> tank;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        while (sum && tank.back().first >= a)
        {
            sum -= tank.back().second;
            tank.pop_back();
        }
        tank.emplace_back(a, k-sum);
        sum = k;
        ans += tank.front().first;
        tank.front().second--; sum--;
        if (tank.front().second == 0)
            tank.pop_front();
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
