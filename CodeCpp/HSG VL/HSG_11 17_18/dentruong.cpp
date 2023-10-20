#include<bits/stdc++.h>
using namespace std;

const int maxN=1e3+9;
int n, m, k, u, v, l, e[maxN][maxN], d[maxN], vstd[maxN];
long long cnt[maxN];
vector<int> adj[maxN];
priority_queue<
    pair<pair<int, int>, int>,
    vector<pair<pair<int, int>, int> >,
    greater<pair<pair<int, int>, int> >
> pq;

void dijkstra(int a) {
    vstd[a] = 1;

    for (int i = 0; i < adj[a].size(); i++) if (vstd[adj[a][i]] == 0) {
        if (d[a]+e[a][adj[a][i]] > d[adj[a][i]]) continue;
        d[adj[a][i]] = d[a]+e[a][adj[a][i]];
        pq.push(make_pair(make_pair(d[adj[a][i]], adj[a][i]), a));
    }

    while (pq.size() && vstd[pq.top().first.second]) pq.pop(); if (pq.empty()) return;

    pair<pair<int, int>, int> b = pq.top();
    long long tmp = 0;
    while (pq.size() && pq.top().first == b.first) {
        tmp += cnt[pq.top().second]; pq.pop();
    }

    cnt[b.first.second] = tmp;
    dijkstra(b.first.second);
}

int main() {
    freopen("dentruong.inp", "r", stdin);
    freopen("dentruong.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> k >> u >> v >> l;
        if (k == 1) {
            adj[u].push_back(v);
            e[u][v] = l;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
            e[u][v] = e[v][u] = l;
        }
    }
    for (int i = 1; i <= n; i++) d[i] = 1e9;
    d[1] = 0;
    cnt[1] = 1;
    dijkstra(1);

    cout << d[n] << ' ' << cnt[n] << endl;
}