#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
long long n, timer, vis[N], mark[N];
vector<int> adj[N], ans;

void bfs(int u) {
    queue<int> nxt;
    nxt.push(u);

    while (nxt.size()) {
        u = nxt.front(); nxt.pop();
        ans.push_back(u);
        vis[u] = 1;
        for (int v: adj[u]) {
            if (vis[v] == 0) {
                nxt.push(v);
            }
        }
        while (nxt.size() && vis[nxt.front()]) nxt.pop();
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        if (a != i) adj[a].push_back(i); else mark[i] = 1;
        if (b != i) adj[b].push_back(i); else mark[i] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mark[i] && vis[i] == 0) bfs(i);
    }
    for (int i = 1; i <= n; i++) if (vis[i]) cnt++;
    if (cnt < n) {
        cout << "-1";
        return;
    }
    reverse(ans.begin(), ans.end());
    for (int i: ans) cout << i << '\n';
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
}
