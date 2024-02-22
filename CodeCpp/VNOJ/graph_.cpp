/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    num[u] = thoi diem bat dau tham
    low[u] = gia tri num[] nho nhat trong cay con goc u

    neu la cau thi num[v] == low[v]
    tuc ko co canh noi ra ngoai cay con goc u

    neu la khop thi low[v] >= num[u] (voi cac cay goc v ke goc u)
    tuc muon di ra ngoai phai di qua u

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
int n, m, timer;
int num[N], low[N], isCut[N], cntBridge, cntCut;
vector<int> adj[N];

void init(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p = -1) {
    int nChild = 0;
    num[u] = low[u] = ++timer;
    for (int v: adj[u]) if (v != p) {
        if (num[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            nChild++;

            if (low[v] == num[v]) cntBridge++;
            if (p == -1 && nChild > 1) isCut[u] = 1;
            if (p != -1 && low[v] >= num[u]) isCut[u] = 1;
        }
        else low[u] = min(low[u], num[v]);
    }
}

void solve(void) {
    for (int i = 1; i <= n; i++)
        if (num[i] == 0) dfs(i);
    for (int i = 1; i <= n; i++) cntCut += isCut[i];
    cout << cntCut << ' ' << cntBridge;
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
