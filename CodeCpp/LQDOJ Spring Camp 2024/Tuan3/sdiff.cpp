#include<bits/stdc++.h>
using namespace std;

int n, p, q, m, k, a;
deque<int> dq_max, dq_min;

void solve()
{
    cin >> n >> p >> q >> m >> k;
    long long ans = 0; int j = 1;
    dq_max.push_back((1ll*p+q)%m);
    dq_min.push_back((1ll*p+q)%m);
    for (int i = 1; i <= n; i++)
    {
        while (j <= n && dq_max.front() - dq_min.front() <= k)
        {
            j++;
            int v = (1ll*p*j+q)%m;
            while (!dq_max.empty() && dq_max.back() <= v)
                dq_max.pop_back();
            while (!dq_min.empty() && dq_min.back() >= v)
                dq_min.pop_back();
            dq_max.push_back(v);
            dq_min.push_back(v);

        }
        ans += j-i;
        if (!dq_max.empty() && (1ll*p*i+q)%m == dq_max.front()) dq_max.pop_front();
        if (!dq_min.empty() && (1ll*p*i+q)%m == dq_min.front()) dq_min.pop_front();
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
