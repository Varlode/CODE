/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    truy van 1:
    ko la cau thi luon dung
    neu la cau thi:
        xoa cau se luon tao ra 2 tplt
        co dinh cay con trong 2 dau mut cua cau
        euler tour de ktra A, B co cung cay con hay ko

    truy van 2:
    ko la khop thi luon dung
    neu la khop thi:
        xoa khop se tao ra nhieu tplt
        nhung co the kiem tra lien thong cua cac cay con cua khop nhanh:
        nhay nhi phan len dinh con truc tiep:
            2 dinh cung nam trong cay, hoac ngoai cay
            hoac deu cung thuoc 1 tplt ngoai cay con goc khop

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 1e5+1;
int n, m, q, timer, A, B;
int num[N], low[N], tail[N], isKhop[N], h[N];
int par[N][21];
vector<int> adj[N];

void init() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p = -1) {
    int nChild = 0;
    num[u] = low[u] = ++timer;
    for (int v: adj[u]) if (v != p) {
        if (!num[v]) {
            par[v][0] = u;
            h[v] = h[u]+1;
            nChild++;

            dfs(v, u);

            low[u] = min(low[u], low[v]);
            if (p == -1) {
                if (nChild > 1) isKhop[u] = 1;
            }
            else if (low[v] >= num[u]) isKhop[u] = 1;
        }
        else low[u] = min(low[u], num[v]);
    }
    tail[u] = timer;
}

/*
    de dinh A trong cay con U thi num[u] < num[a] < tail[u];
*/

bool insideTree(int u, int root) {
    return num[root] <= num[u] && num[u] <= tail[root];
}

int getChild(int u, int root) {
    for (int i = 20; i >= 0; i--)
        if (h[par[u][i]] > h[root]) u = par[u][i];
    return u;
}

bool queryEdge(int G1, int G2) {
    if (num[G2] < num[G1]) swap(G2, G1);

    if (low[G2] != num[G2]) return true;
    if (insideTree(A, G2) == insideTree(B, G2)) return true;
    return false;
}

bool queryVertex(int C) {
    if (!isKhop[C]) return true;

    int pA = 0, pB = 0;
    if (insideTree(A, C)) pA = getChild(A, C);
    if (insideTree(B, C)) pB = getChild(B, C);

    if (pA == pB) return true;
    if (!pA && low[pB] < num[C]) return true;
    if (low[pA] < num[C] && !pB) return true;
    if (pA && pB && low[pA] < num[C] && low[pB] < num[C]) return true;
    return false;
}

void solve(void) {
    dfs(1);
    for (int j = 1; j <= 20; j++) for (int i = 1; i <= n; i++)
        par[i][j] = par[par[i][j-1]][j-1];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type >> A >> B;
        if (type == 1) {
            int G1, G2; cin >> G1 >> G2;
            if (queryEdge(G1, G2)) cout << "yes\n";
            else cout << "no\n";
        }
        else {
            int C; cin >> C;
            if (queryVertex(C)) cout << "yes\n";
            else cout << "no\n";
        }
    }
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
