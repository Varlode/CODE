#include<bits/stdc++.h>
using namespace std;

const int N = 4e5+10;
int n, m, k;
vector<int> bucket[N], hold[N], take;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x; cin >> x;
            bucket[i].push_back(x);
        }
        reverse(bucket[i].begin(), bucket[i].end());
        take.push_back(i);
    }

    int ans = 2*n;
    while (!take.empty())
    {
        int i = take.back(); take.pop_back();
        int color = bucket[i].back(); bucket[i].pop_back();
        hold[color].push_back(i);
        if ((int) hold[color].size() == 2)
        {
            while (!hold[color].empty())
            {
                if (!bucket[hold[color].back()].empty())
                    take.push_back(hold[color].back());
                hold[color].pop_back();
            }
            ans -= 2;
        }
    }
    if (ans == 0) cout << "Yes\n";
    else cout << "No\n";
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
