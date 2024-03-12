#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
int n, a[SIZE];
vector<int> person_before;

void solve()
{
    a[0] = 1e9+100;
    person_before.push_back(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (a[person_before.back()] <= a[i])
            person_before.pop_back();
        cout << person_before.back() << ' ';
        person_before.push_back(i);
    }
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
