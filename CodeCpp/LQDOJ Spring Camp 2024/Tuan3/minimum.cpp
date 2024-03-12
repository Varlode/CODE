#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
int n, k, a[SIZE], ans[SIZE];
deque<int> pos;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (!pos.empty() && a[pos.back()] >= a[i])
            pos.pop_back();
        pos.push_back(i);
        if (i-pos.front() >= k) pos.pop_front();
        ans[i] = a[pos.front()];
    }
    for (int i = k; i <= n; i++)
        cout << ans[i] << '\n';
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
