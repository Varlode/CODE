#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n;
pair<int, int> a[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;

    vector< pair<int, int> > profit, un_profit;
    for (int i = 1; i <= n; i++) {
        if (a[i].second - a[i].first > 0) profit.push_back(a[i]);
        else un_profit.push_back(a[i]);
    }

    sort(profit.begin(), profit.end(), [&] (auto x, auto y) {
        if (x.first < y.first) return true;
        if (x.first == y.first && x.second > y.second) return true;
        return false;
    });

    sort(un_profit.begin(), un_profit.end(), [&] (auto x, auto y) {
        if (x.second > y.second) return true;
        if (x.second == y.second && x.first < y.first) return true;
        return false;
    });

    int i = 1;
    for (auto p: profit)
    {
        a[i++] = p;
    }
    for (auto p: un_profit)
    {
        a[i++] = p;
    }
    long long ans = a[1].first, sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += a[i].second;
        if (sum < a[i+1].first)
        {
            ans += a[i+1].first - sum;
            sum = 0;
        }
        else sum -= a[i+1].first;
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
    int t = 1;
//    cin >> t;
    while (t--)
    {
        solve();
    }
}
