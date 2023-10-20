#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define ll long long
#define int long long

const int N = 1e6+100;
const int LOG = 21;

int n, d1[N], d2[N], ans;
vector<int> adj[N];
vector<pair<int, int> > edg[N];

int par[N][21], high[N], cnt[N], dp[N];

void build_lca(int u, int p=-1) {
    for (int v: adj[u]) {
        if (v == p) continue;
        high[v] = high[u] + 1;
        par[v][0] = u;
        build_lca(v, u);
    }
}

int lca(int u, int v)
{
    if(high[v] > high[u])
        return lca(v, u);
    FOR(i, LOG, 0)
        if(high[par[u][i]] >= high[v])
            u = par[u][i];
    if(u == v)
        return u;
    FOR(i, LOG, 0)
        if(par[u][i] != par[v][i])
            u = par[u][i],
            v = par[v][i];
    return par[u][0];
}

void dfs(int u, int p=-1) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        dfs(v); 
        cnt[u] += cnt[v];
        ans += min(edg[u][i].fi, edg[u][i].se*cnt[v]);
    }
}

void setData() {
    cin >> n;
    FOR(i, 1, n-1) {
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edg[a].push_back({c1, c2});
        edg[b].push_back({c1, c2});
    }
}

main() {
    setData();
    high[0] = -1;
    FOR(i, 1, LOG)
        FOR(j, 1, n)
            par[j][i] = par[par[j][i - 1]][i - 1];
    build_lca(1);
    FOR(i, 2, n) {
        cnt[i-1]++, cnt[i]++;
        cnt[lca(i, i-1)] -= 2;
    }
    dfs(1);
    cout << ans;
}