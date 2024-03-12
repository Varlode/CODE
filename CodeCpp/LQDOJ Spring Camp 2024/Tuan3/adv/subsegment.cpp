#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, a[N], l[N], val[N];
vector<int> hold;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (!hold.empty() && a[hold.back()] >= a[i])
            hold.pop_back();
        l[i] = hold.empty()? 0: hold.back();
        hold.push_back(i);
    }
    hold.clear();
    for (int i = n; i >= 1; i--)
    {
        while (!hold.empty() && a[hold.back()] >= a[i])
            hold.pop_back();
        int r = hold.empty()? n+1: hold.back();
        hold.push_back(i);
        val[r-l[i]-1] = max(val[r-l[i]-1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        val[i] = max(val[i], val[i+1]);
    }
    for (int i = 1; i <= n; i++)
        cout << val[i] << ' ';
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
