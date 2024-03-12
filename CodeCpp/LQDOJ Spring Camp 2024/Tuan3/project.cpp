#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, H, S, D, a[N];
long long ans;
deque<int> dq_max;

void solve()
{
    cin >> n >> H >> S >> D;
    int LIMIT = (H+D)/S, recent_num = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int j = 2;
    for (int i = 1; i <= n; i++)
    {
        if (!dq_max.empty() && dq_max.front() <= i)
            dq_max.pop_front();
        while (j <= n && j <= i+LIMIT+1)
        {
            while (!dq_max.empty() && a[dq_max.back()] <= a[j])
                dq_max.pop_back();
            dq_max.push_back(j);
            j++;
        }
        if (a[i] > recent_num)
        {
            ans += 1ll*(a[i] - recent_num)*H;
            recent_num = a[i];
        }
        ans += 1ll*recent_num*S;
        if (!dq_max.empty() && recent_num > a[dq_max.front()])
        {
            ans += 1ll*(recent_num - a[dq_max.front()])*D;
            recent_num = a[dq_max.front()];
        }
    }
    ans += 1ll*recent_num*D;
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
