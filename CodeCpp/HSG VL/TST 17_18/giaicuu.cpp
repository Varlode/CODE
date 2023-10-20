#include<bits/stdc++.h>
using namespace std;

const int maxN = 109;
int a[maxN][maxN], b[maxN][maxN], vstd[maxN][maxN];
int m, n, u, v, T, k;
int mx[4] = {-1, 0, 1, 0}, my[4] = {0, 1, 0, -1};

struct node {
    int idx, val;
};

node operator + (const node& a, const node& b) {
    if (a.val < b.val) return a; else return b;
}

class seq {
    node tree[maxN*maxN*4];
public:
    void build() {
        for (int i = 1; i <= 4*n*m ; i++)
            tree[i].val = 1e9;
    }

    void update(int i, int l, int r, int u, int v) {
        if (u < l || r < u) return;
        if (l == r) {
            tree[i].val = v;
            tree[i].idx = u;
            return;
        }
        int m = l+(r-l)/2;
        update(i*2, l, m, u, v);
        update(i*2+1, m+1, r, u, v);

        tree[i] = tree[i*2] + tree[i*2+1];
    }
    int idx(int i) {return tree[i].idx;}
    int val(int i) {return tree[i].val;}

} st;

void bfs(int x, int y) {
    if (b[x][y] > T) return;
    if (x == u && y == v) return;
    if (vstd[x][y]) return;
    vstd[x][y] = 1;
    st.update(1, 1, n*m, (x-1)*n+y, 1e9);

    for (int i = 0; i < 4; i++) {
        if (x+mx[i] < 1 || m < x+mx[i]) continue;
        if (y+my[i] < 1 || n < y+my[i]) continue;
        if (vstd[x+mx[i]][y+my[i]]) continue;
        if (b[x][y]+a[x+mx[i]][y+my[i]] < b[x+mx[i]][y+my[i]]) {
            b[x+mx[i]][y+my[i]] = b[x][y]+a[x+mx[i]][y+my[i]];
            st.update(1, 1, n*m, (x+mx[i]-1)*n+(y+my[i]), b[x+mx[i]][y+my[i]]);
        }
    }
    int tmp = st.idx(1);
    if (tmp % n == 0) {
        bfs(tmp/n, n);
    } else {
        bfs(tmp/n+1, tmp-tmp/n*n);
    }
}

int main() {
    freopen("giaicuu.inp", "r", stdin);
    freopen("giaicuu.out", "w", stdout);
    cin >> k;
    while (k--) {
        cin >> m >> n;
        st.build();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                b[i][j] = 1e9;
                vstd[i][j] = 0;
            }
        }
        cin >> u >> v >> T;
        b[1][1] = a[1][1];
        st.update(1, 1, n*m, 1, a[1][1]);
        bfs(1, 1);
        if (T-b[u][v] >= 0) cout << "YES\n" << T-b[u][v] << endl; else cout << "NO\n";
    }
}