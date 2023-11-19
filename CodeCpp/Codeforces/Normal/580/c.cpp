#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, m, cat[N], ans;
vector<int> adj[N];

void dfs(int u, int p = -1, int sum = 0) {
    int cnt = 0;
    sum += cat[u];
    if (sum > m) return;
    for (int v: adj[u]) if (v != p) {
        cnt++;
        if (cat[u]) dfs(v, u, sum);
        else dfs(v, u);
    }
    if (cnt == 0) ans++;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << ans;
}