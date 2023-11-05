#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> toi(n + 1), tu(n + 1);
    vector< vector<int> > ed(n + 1, vector<int>()), fall(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        ed[y].push_back(x);
        fall[x].push_back(y);
        toi[y]++;
        tu[x]++;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < toi[i]; j++) {
            
        }
        
    }
    
    // for (int i = 1; i <= n; i++)
    //     cout << tu[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << toi[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << fall[i] << ' ';
    // cout << endl;

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}