#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+100;
int n, a, b;
int not_prime[SIZE];

void solve()
{
    cin >> n >> a >> b;
    not_prime[1] = 1;
    int ans = 0;
    for (int i = 2; i*i <= n; i++)
    {
        if (not_prime[i] == 1) continue;
        for (int j = i*2; j <= n; j += i)
        {
            not_prime[j] = 1;
        }
        ans++;
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
    // cin >> Test;
    while (Test--)
    {
        solve();
    }
}
