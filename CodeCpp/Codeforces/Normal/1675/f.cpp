#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back

const int INF = 0x3f3f3f3f;
const int N = 1e6;
int k, n, mark[N], dy[N], x, y, cnt_e;
vector<int> adj[N], _adj[N];

void reset(int u) {
    cnt_e = 0;
    FOR(i, 1, u) {
        mark[i] = 0;
        adj[i].clear();
        _adj[i].clear();
        dy[i] = 0;
    }
}

void cut(int u, int p=-1) {
    mark[u] = mark[u] || u == x || u == y;
    for (int v: _adj[u]) if (v != p) {
        cut(v, u);
        if (mark[v]) {
            cnt_e++;
            mark[u] = 1;
            adj[v].pb(u);
            adj[u].pb(v);
        }
    }    
}

void dfs(int u, int p=-1) {
    for (int v: adj[u]) if (v != p) {
        dy[v] = dy[u] + 1;
        dfs(v, u);
    }
}

main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        reset(n);
        cin >> x >> y;
        FOR(i, 1, k) {
            int a; cin >> a;
            mark[a] = 1;
        }
        REP(i, n-1) {
            int u, v;
            cin >> u >> v;
            _adj[u].pb(v);
            _adj[v].pb(u);
        }
        cut(x);
        dfs(y);
        cout << 2*cnt_e-dy[x] << endl;
    }
}