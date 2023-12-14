#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
// #define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define eps double(1e-9)
#define vii vector<int>
#define pii pair<int,int>
#define p2i pair<int,pii>
#define endl '\n'

using namespace std;

const int N = 5e4 + 5;
const int MN = 2e3 + 5;
const int mod = 1e9 + 7;
const int inf = 1e18 + 7;
const bool Emily = false;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return l+rng()%(r-l+1);
}

bool minimize(int &a, int b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

bool maximize(int &a, int b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int n, m, source;
vector <int> adj[N];

int depth[N], cnt[N], T[N][20];
#define bit(x, i) (1 & (x >> i))
int lca(int u, int v) {
    if (cnt[u] < cnt[v]) swap(u, v);
    int del = cnt[u] - cnt[v];

    repd(i, 18, 0) if (bit(del, i)) u = T[u][i];

    if (u == v) return v;
    repd(i, 18, 0)
        if (T[u][i] != T[v][i]) {
            u = T[u][i]; v = T[v][i];
        }

    return T[u][0];
}

void solve(void) {
    cin >> n >> m >> source;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    rep(i, 1, n) depth[i] = inf;
    queue <int> q;

    q.push(source);
    depth[source] = 1;
    T[source][0] = -1;

    while (q.size()) {
        int u = q.front(); q.pop();

        cnt[u] = (T[u][0] == -1 ? 0 : cnt[T[u][0]] + 1);
        for (int j = 1; (1 << j) <= n; ++j) {
            if (T[u][j - 1] != -1) {
                T[u][j] = T[T[u][j - 1]][j - 1];
            } else T[u][j] = -1;
        }

        for (int v : adj[u]) {
            if (depth[v] > depth[u] + 1) {
                depth[v] = depth[u] + 1;
                T[v][0] = u;
                q.push(v);
            } else {
                if (depth[v] == depth[u] + 1) {
                    T[v][0] = lca(T[v][0], u);
                }
            }
        }
    }

    // rep(i, 1, n - 1) rep(j, i + 1, n) cout << i << ' ' << j << ' ' << lca(i, j) << endl;

    int query; cin >> query;
    while (query-- ) {
        int sink, d;
        cin >> sink >> d;

        if (depth[sink] > n || depth[sink] < d + 1) {
            cout << 0 << endl;
            continue ;
        }

        repd(i, 18, 0)
            if (T[sink][i] != -1 && depth[T[sink][i]] >= d + 1) sink = T[sink][i];

        cout << (depth[sink] != d + 1 ? -1 : sink) << endl;
    }
}

signed main()
{
    #define task "path"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // freopen(task".inp", "r", stdin);
    // freopen(task".out", "w", stdout);

    if (Emily) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}
