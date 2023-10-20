#include<bits/stdc++.h>
using namespace std;

const int maxN=1e3+9;
int n, m, d[maxN], vstd[maxN], v[maxN][maxN], ans = 0;
vector<int> adj[maxN];

priority_queue<
    pair<int, pair<int, int> >, 
    vector<pair<int, pair<int, int> > >, 
    greater<pair<int, pair<int, int> > > 
> pq;

priority_queue<
    pair<int, int>,
    vector<pair<int, int> >,
    greater<pair<int, int> >
> min_queue;

void dijkstra(int a) {
    vstd[a] = 1;
    ans = max(ans, d[a]);

    for (int i = 0; i < adj[a].size(); i++) if (vstd[adj[a][i]] == 0) {
        if (v[a][adj[a][i]] < d[adj[a][i]]) {
            d[adj[a][i]] = v[a][adj[a][i]];
            min_queue.push(make_pair(d[adj[a][i]], adj[a][i]));
        }
    }

    while (min_queue.size() && vstd[min_queue.top().second]) min_queue.pop();
    if (min_queue.empty()) return;

    pair<int, int> tmp = min_queue.top(); min_queue.pop();
    dijkstra(tmp.second);
}

int main() {
    freopen("giaothong.inp", "r", stdin);
    freopen("giaothong.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        v[x][y] = v[y][x] = z;
        // pq.push(make_pair(z, make_pair(x, y)));
    }
    for (int i = 1; i <= n; i++)
        d[i] = 1e9;
    d[1] = 0;
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans;
}