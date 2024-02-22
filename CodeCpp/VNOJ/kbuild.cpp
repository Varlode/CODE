/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / !..! \       / >--< \
 !  ___  \_/\---'         \/ !! \/       \l  \ l/
 !_!!  !_!!                !_''_!         l_ll_l

*/

/* NHAP -----------------------

    bai nay co 1 trick, la danh dau nhung duong di bang cach bien no thanh chu trinh
    va cac duong con lai chac chan chua di
    tu do duong ko nam trong chu trinh se la cau
    bien bai toan thanh bai bai toan dem so luong cau

    nma trick nay bi lo
    phai dung lca de danh dau cay con
    se danh dau 2 dinh += 1, va lca cua chung -=2

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int n, m, h[N], par[N][21], f[N], ans;
vector<int> adj[N];

void init(void) {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void preDfs(int u, int p = -1) {
    for (int v: adj[u]) if (v != p) {
        h[v] = h[u]+1;
        par[v][0] = u;
        preDfs(v, u);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[v] > h[u]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 17; i >= 0; i--) if ((k >> i) & 1) {
            u = par[u][i];
        }
    }
    if (u == v) return u;

    for (int i = 17; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void dfs(int u, int p = -1) {
    for (int v: adj[u]) if (v != p) {
        dfs(v, u);
        f[u] += f[v];
    }
    if (p != -1 && f[u] == 0) ans++;
}

void solve(void) {
    preDfs(1);
    for (int j = 1; j <= 17; j++) for (int i = 1; i <= n; i++)
        par[i][j] = par[par[i][j-1]][j-1];

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        f[u]++; f[v]++;
        f[lca(u, v)] -= 2;
    }

    dfs(1);
    cout << ans;
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
