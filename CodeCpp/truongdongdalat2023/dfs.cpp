#include <bits/stdc++.h>
using namespace std;

const int N = 300300, MOD = 824613;

int n, k, ans, w[N], st[N*4];

vector<int> adj[N], leaf;
deque<int> cur;
map<long long, int> direct;

inline void build() {
    for (int i = 1; i <= 4*n; i++) st[i] = 1e9;
}

void upd(int i, int l, int r, int u, int v) {
    if (u < l || r < u) return;
    if (l == r) {
        st[i] = v;
        return;
    }
    int m = l+(r-l)/2;
    upd(i*2, l, m, u, v);
    upd(i*2+1, m+1, r, u, v);
    st[i] = min(st[i*2], st[i*2+1]);  
}

void dfs (int u, int p = -1) {
    int wait = 0;
    upd(1, 1, n, u, w[u]);
    cur.push_back(u);
    if (cur.size() > k) {
        wait = cur.front(); cur.pop_front();
        upd(1, 1, n, wait, 1e9);
    }
    if (cur.size() == k) {
        ans = max(ans, st[1]);
        if (direct[cur.front() * MOD + cur.back()]) {
            if (wait > 0) {
                cur.push_front(wait);
                upd(1, 1, n, wait, w[wait]);
            }
            cur.pop_back(); upd(1, 1, n, u, 1e9);
            return;
        }
        else direct[cur.front() * MOD + cur.back()] = direct[cur.back() * MOD + cur.front()] = 1; 
    }
    // if (cur.size() == k) {for (int i: cur) cout << i << ' '; cout << st[1] << endl;}
    for (int v: adj[u]) if (v != p) dfs(v, u);

    if (wait > 0) {
        cur.push_front(wait);
        upd(1, 1, n, wait, w[wait]);
    }
    cur.pop_back(); upd(1, 1, n, u, 1e9);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build();
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) dfs(i); 
    }
    cout << ans;
}