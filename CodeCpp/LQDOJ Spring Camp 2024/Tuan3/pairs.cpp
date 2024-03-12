#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
int n, a[SIZE], L[SIZE], R[SIZE];
long long ans;
vector<int> great;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (!great.empty() && a[great.back()] < a[i])
            great.pop_back();
        L[i] = great.empty()? 0: great.back();
        great.push_back(i);
    }
    great.clear();
    for (int i = n; i >= 1; i--)
    {
        while (!great.empty() && a[great.back()] < a[i])
            great.pop_back();
        R[i] = great.empty()? n+1: great.back();
        great.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (L[i] != 0) + (R[i] != n+1) - (a[L[i]] == a[i]);
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
