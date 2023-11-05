#include<bits/stdc++.h>
using namespace std;

pair<int, int> a[1000];

void solve()
{
    int n; cin >> n;
    int cnt = 1;
    vector<int> a(n + 1, 0);
    if (n & 1)
    {
        cout << "yes" << endl;
        for (int i = 1; i <= n; i++)
            if (a[i] == 0)
            {   
                if (i + cnt > n) {
                    cout << i << " " << (2*n + 1) - i << endl;
                    continue;
                }
                cout << i << " " << (2*n + 1) - (i + cnt) << endl;
                a[i + cnt] = i;
                cnt++;
            } else 
                cout << i << " " << (2*n + 1) - a[i] << endl;
    } else cout << "no" << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}