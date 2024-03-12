#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, a[N], A, B;
long long pref[N], ans = -1e18;
deque<int> hold;

void solve()
{
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
    }
    for (int i = 0; i <= n-A; i++)
    {
        while (!hold.empty() && pref[hold.back()] >= pref[i])
            hold.pop_back();
        hold.push_back(i);
        if (!hold.empty() && i+A-hold.front() > B)
            hold.pop_front();
        ans = max(ans, pref[i+A] - pref[hold.front()]);
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
