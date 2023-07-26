#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, X; cin >> n >> k >> X;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}   