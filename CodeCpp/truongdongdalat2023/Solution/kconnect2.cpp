#define TASK ""
#include<bits/stdc++.h>

using namespace std;

using lli = long long int;

using ii = pair<int, int>;
#define fi first
#define se second

template<class X, class Y> bool maximize(X &A, const Y &B) {return A < B ? A = B, true : false;}
template<class X, class Y> bool minimize(X &A, const Y &B) {return A > B ? A = B, true : false;}

const int N = 3e5 + 10;
const int LGN = 20;

int n, m, k;
int anc[N];
int par[N][LGN], high[N], LG2[N];
vector<ii> adj[N];
int pre[N], id[N], res[N];

void dfs(int u, int parU) {
    for (ii v : adj[u]) {
        if(v.fi == parU) continue;

        id[v.fi] = v.se;
        high[v.fi] = high[u] + 1;
        par[v.fi][0] = u;
        dfs(v.fi, u);
    }
}

void init() {
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if(par[i][j - 1] != -1) par[i][j] = par[par[i][j - 1]][j - 1];
}

int find_LCA(int u, int v) {
    if(high[u] < high[v]) return find_LCA(v, u);

    int LG = LG2[high[u]];

    for (int i = LG; i >= 0; i--)
        if(high[u] - (1 << i) >= high[v]) u = par[u][i];

    if(u == v) return u;

    for (int i = LG; i >= 0; i--) {
        if(par[u][i] == -1 || par[v][i] == -1) continue;

        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

void init_dsu() {
    for (int i = 1; i <= n; i++)
        anc[i] = -1;
}

int findroot(int u) {
    return anc[u] < 0 ? u : anc[u] = findroot(anc[u]);
}

void join(int x, int y) {
    x = findroot(x);
    y = findroot(y);

    if(x == y) return;

    if(anc[y] < anc[x]) swap(y, x);

    anc[x] += anc[y];
    anc[y] = x;
}

void dfs2(int u, int parU) {
    for (ii v : adj[u]) {
        if(v.fi == parU) continue;

        dfs2(v.fi, u);
        pre[u] += pre[v.fi];
    }
}

int main() {
    if(fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    init_dsu();
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if(findroot(u) == findroot(v)) continue;
        join(u, v);
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    for (int i = 2; i <= n; i++)
        LG2[i] = LG2[i / 2] + 1;

    dfs(1, 0);

    init();
    for (int i = 1; i <= k; i++) {
        int u, v; cin >> u >> v;
        pre[u] += 1; pre[v] += 1; pre[find_LCA(u, v)] -= 2;
    }

    dfs2(1, 0);

    for (int i = 1; i <= n; i++)
        if(pre[i] >= 1) res[id[i]] = 1;

    for (int i = 1; i <= m; i++)
        cout << res[i] << ' ';

    return 0;
}
