#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
int n, a[SIZE], mn[SIZE], mx[SIZE];
long long ans;
vector<int> pos_mn, pos_mx;
int pre_mn[SIZE], pre_mx[SIZE];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (pos_mn.size() && a[pos_mn.back()] >= a[i])
            pos_mn.pop_back();
        while (pos_mx.size() && a[pos_mx.back()] <= a[i])
            pos_mx.pop_back();

        if (pos_mn.empty()) mn[i] = 0;
        else mn[i] = pos_mn.back();

        if (pos_mx.empty()) mx[i] = 0;
        else mx[i] = pos_mx.back();

        pos_mn.push_back(i);
        pos_mx.push_back(i);
    }

    pos_mn.clear(); pos_mx.clear();
    for (int i = n; i >= 1; i--)
    {
        if (pre_mx[a[i]] == 0) pre_mx[a[i]] = n+1;
        if (pre_mn[a[i]] == 0) pre_mn[a[i]] = n+1;

        while (pos_mn.size() && a[pos_mn.back()] >= a[i])
            pos_mn.pop_back();
        while (pos_mx.size() && a[pos_mx.back()] <= a[i])
            pos_mx.pop_back();

        if (pos_mn.empty())
            ans -= 1ll*a[i]*(min(n+1, pre_mn[a[i]])-i)*(i-mn[i]);
        else
            ans -= 1ll*a[i]*(min(pos_mn.back(), pre_mn[a[i]])-i)*(i-mn[i]);

        pre_mn[a[i]] = i;
        if (pos_mx.empty())
            ans += 1ll*a[i]*(min(n+1, pre_mx[a[i]])-i)*(i-mx[i]);
        else
            ans += 1ll*a[i]*(min(pos_mx.back(), pre_mx[a[i]])-i)*(i-mx[i]);

        pre_mx[a[i]] = i;

        pos_mn.push_back(i);
        pos_mx.push_back(i);
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
