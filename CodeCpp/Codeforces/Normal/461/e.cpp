#include<bits/stdc++.h>
using namespace std;

const int N = 4*1e5;
vector<pair<int, int> > e[N];
int n, m;
int dp[N], v[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[w].push_back({u, v});
    }

    for (int i = 1; i <= 3*1e5+100; i++) {
        for (auto a: e[i]) 
            v[a.second] = 0;
        for (auto a: e[i])
            v[a.second] = max(v[a.second], dp[a.first] + 1);
        for (auto a: e[i])
            dp[a.second] = max(dp[a.second], v[a.second]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) 
        ans = max(ans, dp[i]);
    cout << ans;
}