#include<bits/stdc++.h>
using namespace std;

long long fd[1000006], bd[1000006];

void solve()
{
    int n, m, q, a, b;
    cin >> n >> m >> q >> a >> b;
    
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        fd[x] = x;
        bd[x] = x;
    }
    bd[0] = -5e6 - 6; fd[n + 1] = 5e6 + 6;
    for (int i = 1; i <= n; i++)
        if (bd[i] == 0) bd[i] = bd[i - 1];
    for (int i = n; i >= 1; i--)
        if (fd[i] == 0) fd[i] = fd[i + 1];
    for (int i = 0; i < q; i++)
    {
        long long x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        cout << min((y - x) * a, (fd[x] - x) * a + (y - bd[y]) * a + (bd[y] - fd[x]) * b) << endl;
    }
    
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}   