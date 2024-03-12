#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n;
int mark[N][6], b[N];

void solve()
{
    cin >> n;
    for (int j = 1; j <= 5; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int a; cin >> a;
            mark[a][j] = i;
        }
    }
    for (int i = 1; i <= n; i++) b[i] = i;
    sort(b+1, b+1+n, [&] (auto x, auto y)
    {
        int le = 0;
        for (int i = 1; i <= 5; i++)
        {
            if (mark[x][i] < mark[y][i]) le++;
        }
        return le > 2;
    });
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
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
