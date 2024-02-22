/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    tuong du bai tim cau, bai nay se tim khop
    neu la khop se tinh cac cay con bi co lap voi tplt lons

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define ld long double

const int N = 2e4+1, M = 2e5+1;
int n, m, root, nRoot, timer;
int num[N], low[N], nChild[N], vis[N], used[M];
vector<int> adj[N];
ld add, sub, ans;

struct EDGE {
    int u, v;
} e[M];

void init(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i: adj[u]) {
            int v = e[i].u+e[i].v-u;
            if (vis[v]) continue;
            nRoot++;
            vis[v] = 1;
            q.push(v);
        }
    }
}

void dfs(int u) {
    int cnt = 0, nRest = 0;
    vector<int> child;

    nChild[u] = 1;
    num[u] = low[u] = ++timer;
    for (int i: adj[u]) if (!used[i]) {
        used[i] = 1;
        int v = e[i].u+e[i].v-u;

        if (!num[v]) {
            dfs(v);

            nChild[u] += nChild[v];
            cnt++;
            low[u] = min(low[u], low[v]);

            if (low[v] >= num[u]) ans += (ld) nChild[v]/n*(nRoot-nChild[v]-1);
            else nRest += nChild[v];
        }
        else low[u] = min(low[u], num[v]);
    }
    nRest += nRoot-nChild[u];
    ans += (ld) nRest/n*(nRoot-nRest-1);
}

void solve(void) {
    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            root = i;
            nRoot = 0;
            bfs(i);
            dfs(i);
        }
    }
    cout << fixed << ans/2;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    init();
    solve();
}
