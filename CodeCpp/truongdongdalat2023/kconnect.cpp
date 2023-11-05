#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ppi pair<int, pi>
#define fi first
#define se second

const int N = 300300;
int n, m, k;
int imp[N], a[N], b[N];
vector<int> adj[N];
priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

int par[N];
int find(int u) {
    return u == par[u]? u: par[u] = find(par[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) par[v] = u;
}

void cut(int u, int p = -1) {
    for (int v: adj[u]) if (v != p) {
        cut(v, u);
        if (imp[v]) imp[u] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
    int root;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        imp[x] = 1;
        root = x;
    }
    int l = 1, r = m; 
    while (l < r) {
        int mid = l+(r-l)/2;
        for (int i = 1; i <= n; i++) par[i] = i;
        for (int i = 1; i <= mid; i++) join(a[i], b[i]);   
        bool ok = true;
        for (int i = 1; i < k; i++) {
            if (find(imp[i]) == find(imp[i+1])) {
                ok = false;
                break;
            }
        }
        if (ok) r = mid-1;
        else l = mid+1;
    }
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= l; i++) join(a[i], b[i]);
    cut(root);
    for (int i = 1; i < m; i++, cout << ' ') {
        if (imp[a[i]] && imp[b[i]]) cout << 1;
        else cout << 0;
    }
    cout << (imp[a[m]] && imp[b[m]]);
}
