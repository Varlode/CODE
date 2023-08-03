#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+9;
int n, m, x, y;
int vstd[maxN], ans[maxN];
vector<pair<int, int> > g[maxN];

struct node {
    int val, idx;
    node() {
        val = 1e9;
        idx = 0;
    }
};

node operator + (const node& a, const node& b) {
    if (a.val > b.val) return b; else return a;
}

class seg {
    node tree[4*maxN];
public:
    void update(int i, int l, int r, int u, int v) {
        if (u < l || r < u) return;
        if (l == r) {
            tree[i].val = v;
            tree[i].idx = u;
            return;
        }
        int m = l + (r-l)/2;
        update(i*2, l, m, u, v);
        update(i*2+1, m+1, r, u, v);
        
        tree[i] = tree[i*2] + tree[i*2+1];
    }

    int idx() {return tree[1].idx;}
    int val() {return tree[1].val;}
} st;

void dijskstra(int a) {
    if (vstd[a] == 1) return;
    st.update(1, 1, n, a, 1e9);
    vstd[a] = 1;

    for (int i = 0; i < g[a].size(); i++) if (vstd[g[a][i].first] == 0) {
        if (ans[a]+g[a][i].second < ans[g[a][i].first])  {
            ans[g[a][i].first] = ans[a]+g[a][i].second;
            st.update(1, 1, n, g[a][i].first, ans[g[a][i].first]);
        }
    }

    dijskstra(st.idx());
}

int main() {
    freopen("dtqs.inp", "r", stdin);
    freopen("dtqs.out", "w", stdout);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }
    for (int i = 1; i <= n; i++) 
        ans[i] = 1e9+9;
    ans[x] = 0;
    dijskstra(x);
    if (ans[y] != 1e9+9) cout << ans[y]; else cout << -1;
}
