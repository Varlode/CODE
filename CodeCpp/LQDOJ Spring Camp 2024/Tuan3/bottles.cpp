#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
int n, k, a[SIZE];
long long ans, best[SIZE];
deque<int> great;

void solve()
{
    cin >> n >> k;
    great.push_back(0);
    for (int i = 1; i <= n+1; i++)
    {
        cin >> a[i];
        best[i] = best[great.front()]+a[i];
        ans += a[i];
        while (!great.empty() && best[great.back()] >= best[i])
            great.pop_back();
        great.push_back(i);
        if (!great.empty() && great.front() + k < i + 1)
            great.pop_front();
    }
    cout << ans - best[n+1];
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
