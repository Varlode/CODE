//SyruLoveNewTechnology
#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(const int &l, const int &r) {
    return rng() % (r - l + 1) + l;
}

void fre() {
    if(fopen("d13apegamev.inp", "r")) {
        freopen("d13apegamev.inp", "r", stdin);
        freopen("d13apegamev.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

const int MAX = 100005;

int n, q;
int par[MAX];
vector<int> adj[MAX];
int w[MAX];
long long dist[MAX];
pair<int, int> query[MAX];
int id[MAX];
int vtx[MAX];
long long cost[MAX];
int trie[10000005][2], sz;
long long sum[10000005];
int cnt[10000005];
long long res[MAX];

void read() {
    cin >> n >> q;
    for(int i = 2; i <= n; ++i) {
        cin >> par[i];
        adj[par[i]].emplace_back(i);
    }
    for(int i = 2; i <= n; ++i) {
        cin >> w[i];
        dist[i] += w[i];
        for(int u : adj[i])
            dist[u] = dist[i];
    }
    for(int i = 1; i <= q; ++i) {
        cin >> query[i].first >> query[i].second;
        id[i] = i;
    }
}

bool cmp(const int &i, const int &j) {
    if(query[i].second < query[j].second)
        return true;
    return false;
}

void addnum(const long long &n) {
    int u = 0;
    ++cnt[u];
    sum[u] += n;
    for(int i = 46; i >= 0; --i) {
        bool b = ((1LL * n) >> i) & 1;
        if(!trie[u][b]) {
            ++sz;
            trie[u][b] = sz;
        }
        u = trie[u][b];
        ++cnt[u];
        sum[u] += n;
    }
}

void delnum(const long long &n) {
    int u = 0;
    --cnt[u];
    sum[u] -= n;
    for(int i = 46; i >= 0; --i) {
        bool b = ((1LL * n) >> i) & 1;
        u = trie[u][b];
        --cnt[u];
        sum[u] -= n;
    }
}

void add(const int &u) {
    vtx[u] = u;
    int v = u;
    while(v != 1) {
        if(dist[u] <= dist[vtx[par[v]]])
            break;
        int vertex = vtx[par[v]];
        int x = v;
        while(x != 1) {
            if(vtx[par[x]] != vertex)
                break;
            vtx[par[x]] = u;
            x = par[x];
        }
        if(dist[vertex] - dist[par[x]])
            delnum(dist[vertex] - dist[par[x]]);
        if(dist[vertex] - dist[par[v]])
            addnum(dist[vertex] - dist[par[v]]);
        v = x;
    }
    addnum(dist[u] - dist[par[v]]);
}

long long call(int s) {
    if(cnt[0] <= s)
        return sum[0];
    int u = 0;
    long long res = 0;
    int k = s;
    long long num = 0;
    for(int i = 46; i >= 0; --i) {
        if(trie[u][1] && cnt[trie[u][1]] > s) {
            num |= 1LL << i;
            u = trie[u][1];
        }
        else {
            if(trie[u][1]) {
                res += sum[trie[u][1]];
                s -= cnt[trie[u][1]];
            }
            if(!trie[u][0])
                break;
            u = trie[u][0];
        }
    }
    return res + s * num;
}

void solve() {
    sort(id + 1, id + q + 1, cmp);
    int it = 1;
    while(query[id[it]].second == 1)
        ++it;
    vtx[1] = 1;
    for(int i = 2; i <= n; ++i) {
        add(i);
        while(query[id[it]].second == i) {
            res[id[it]] = call(query[id[it]].first);
            ++it;
        }
    }
    for(int i = 1; i <= q; ++i)
        cout << 2 * res[i] << '\n';
}

main() {
    fre();
    read();
    solve();
}
