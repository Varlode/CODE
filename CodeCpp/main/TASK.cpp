#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

const int N = 505;
int n;
int e[N][N], d[N*N], vis[N*N];
vector<pi> edges, ans_e;

struct vertex {
    int id;
    vertex(int n) {id = n;}
    friend bool operator < (const vertex a, const vertex b) {
        return d[a.id] > d[b.id];
    }
};
priority_queue<vertex> pq;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> e[i][j];
        if (i != j) edges.push_back({i, j});
    }
    for (int i = 1; i <= n; i++) d[i] = e[i][i];
    int numNodes = n;
    sort(edges.begin(), edges.end(), [&] (auto a, auto b) {
        return e[a.first][a.second] < e[b.first][b.second];
    });
    for (auto p: edges){
        int u = p.first, v = p.second;
        if (vis[u] || vis[v]) continue;
        d[++numNodes] = e[u][v];
        ans_e.push_back({u, numNodes});
        ans_e.push_back({v, numNodes});
        pq.push(numNodes);
        vis[u] = vis[v] = 1;
    }
    for (int i = 1; i <= n; i++) if (vis[i] == 0) pq.push(i);
    
    while (pq.size() >= 2) {
        vertex u = pq.top(); pq.pop();
        vertex v = pq.top(); pq.pop();
        d[++numNodes] = max(d[u.id], d[v.id]) + 1;
        ans_e.push_back({v.id, numNodes});
        ans_e.push_back({u.id, numNodes});
        pq.push(numNodes);
    }
    cout << numNodes << '\n';
    for (int i = 1; i <= numNodes; i++) cout << d[i] << ' '; cout << '\n';
    cout << pq.top().id << '\n';
    for (auto p: ans_e) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) solve();
}