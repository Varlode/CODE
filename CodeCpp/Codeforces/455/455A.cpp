#include<bits/stdc++.h>
using namespace std;

long long dp[100000];

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int curr = 0;
   
    while (curr < n)
    { 
        dp[a[curr]] += a[curr];
        curr++;
        while (curr < n && a[curr] == a[curr - 1])
        {
            dp[a[curr]] += a[curr];
            curr++;
        }
    }

    for (int i = 1; i <= a[n - 1]; i++)
	    dp[i] = max(dp[i] + dp[i - 2], dp[i - 1]);
    cout << dp[a[n - 1]];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}