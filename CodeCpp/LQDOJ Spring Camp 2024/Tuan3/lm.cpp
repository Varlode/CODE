#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
int n, mark[SIZE], d[SIZE], trace[SIZE];
vector<int> nums;
queue<int> q;
string s;

void solve()
{
    cin >> n;
    cin >> s;
    for (char c: s)
        nums.push_back(c-'0');

    sort(nums.begin(), nums.end());
    for (int num: nums)
    {
        if (num == 0) continue;
        if (num == n)
        {
            cout << n;
            return;
        }
        int v = num;
        mark[v] = 1;
        trace[v] = -1;
        d[v] = num;
        q.push(v);
    }

    while (!q.empty() && mark[0] == 0)
    {
        int u = q.front(); q.pop();
        for (int num: nums)
        {
            int v = (u*10+num)%n;
            if (mark[v]) continue;
            mark[v] = 1;
            trace[v] = u;
            d[v] = num;
            q.push(v);
        }
    }
    if (mark[0])
    {
        int cur = 0;
        vector<int> ans;
        while (cur != -1)
        {
            ans.push_back(d[cur]);
            cur = trace[cur];
        }
        reverse(ans.begin(), ans.end());
        for (int i: ans) cout << i;
        return;
    }
    cout << 0;
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
