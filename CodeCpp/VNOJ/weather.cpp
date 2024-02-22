/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    dem so luong chuyen bay ma lam cho A, B khong lien thong
    tinh tong so luong giua moi cap A, B
    tuc la tim cau, va tinh so luong duong di qua cau

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 101, M = 5001;
int n, m, num[N], low[N], nChild[N], used[M], timer;
vector<int> adj[N];
long long ans;

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

void dfs(int u) {
    nChild[u] = 1;
    num[u] = low[u] = ++timer;
    for (int i: adj[u]) if (!used[i]) {
        used[i] = 1;
        int v = e[i].u+e[i].v-u;
        if (!num[v]) {
            dfs(v);
            nChild[u] += nChild[v];
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                ans += 1ll * nChild[v] * (n-nChild[v]);
            }
        }
        else low[u] = min(low[u], num[v]);
    }
}

void solve(void) {
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
