#include <bits/stdc++.h>
using namespace std;

template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'}; 
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i; 
    return sign ? -x : x; }
 
template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do 
        s += digit_to_char(x%base), x /= base;
    while (x > 0); 
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }
 
template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }
 
template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
 
using  lll =   signed __int128; 
using ulll = unsigned __int128;
 
inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }

#define input cin
#define output cout
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) (u & -u)
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<int>
#define int128 __int128
#define fi first
#define se second
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define pb push_back
#define eb emplace_back
#define TASK "TASK"

const int cs = 3e5 + 7;
const int mod = 1e9 + 7;
const int INF = mod;
const int maxN = 2e3 + 7;
const int block_size = 320;
const ll oo = 1e18 + 7;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }

template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

template<class X, class Y>
    void Add(X &x , const Y &y) {
        x += y;
        if (x > mod) x -= mod;
    }

template<class X, class Y>
    void Sub(X &x, const Y &y) {
        x -= y;
        if (x < 0) x += mod;
    }

// 

struct DSU {
    int n;
    vi parent;
    vi sz;
    DSU() {}
    void resize(int nn) {
        n = nn;
        parent.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1;i <= n;i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    bool Joint(int a,int b) {
        a = Find(a);
        b = Find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int visited[cs];
int dp[cs];
int n,m,k;
pii a[cs];
pii dist[cs];
vector<pii> adj[cs];
int h[cs];
int ST[cs][20];
int ans[cs];

void nhap() {
    input >> n >> m >> k;
    for (int i = 1;i <= m;i++) {
        int x,y;
        input >> x >> y;
        a[i] = {x,y};
    }
    for (int i = 1;i <= k;i++) {
        int x,y;
        input >> x >> y;
        dist[i] = {x,y};
    }
}

bool check(int mid) {
    DSU D;
    D.resize(n);
    for (int i = 1;i <= mid;i++) {
        D.Joint(a[i].first,a[i].second);
    }
    for (int i = 1;i <= k;i++) {
        if (D.Find(dist[i].first) != D.Find(dist[i].second)) return false;
    }
    return true;
}

void DFS(int u,int par) {
    visited[u] = true;
    for (auto it: adj[u]) {
        int v = it.first;
        int w = it.second;
        if (v == par) continue;
        h[v] = h[u] + 1;
        ST[v][0] = u;
        DFS(v,u);
    }
}

void Build() {
    for (int j = 1;mask(j) <= n;j++) {
        for (int i = 1;i <= n;i++) {
            ST[i][j] = ST[ST[i][j - 1]][j - 1];
        }
    }
}

int GetLCA(int u,int v) {
    if (h[u] < h[v]) swap(u,v);
    int log = log2(h[u]);
    for (int i = log;~i;i--) {
        if (h[u] - mask(i) >= h[v]) {
            u = ST[u][i];
        } 
    }
    if (u == v) return u;
    for (int i = log;~i;i--) {
        if (ST[u][i] && ST[v][i] && ST[u][i] != ST[v][i]) {
            u = ST[u][i];
            v = ST[v][i];
        }
    }
    return ST[u][0];
}

void DFS1(int u,int par) {
    visited[u] = 1;
    for (auto it: adj[u]) {
        int v = it.first;
        int w = it.second;
        if (v == par) continue;
        DFS1(v,u);
        dp[u] += dp[v];
        if (dp[v] > 0) ans[w] = 1;
    }
}

void Solve() {
    int l = 1;
    int r = m;
    int pivot = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            pivot = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    // output << pivot << endl;
    DSU D;
    D.resize(n);
    for (int i = 1;i <= pivot;i++) {
        if (D.Joint(a[i].first, a[i].second)) {
            adj[a[i].first].push_back({a[i].second,i});
            adj[a[i].second].push_back({a[i].first,i});
        } 
    }
    mem(visited,0);
    for (int i = 1;i <= n;i++) {
        if (!visited[i]) DFS(i,0);
    }
    Build();
    for (int i = 1;i <= k;i++) {
        int LCA = GetLCA(dist[i].first, dist[i].second);
        dp[dist[i].first]++;
        dp[dist[i].second]++;
        dp[LCA] -= 2;
    }
    mem(visited,0);
    for (int i = 1;i <= n;i++) {
        if (!visited[i]) DFS1(i,0);
    }
    for (int i = 1;i <= m;i++) {
        output << ans[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    // auto TIME1 = chrono::steady_clock::now();
    int T = 1;
    // input >> T;
    while (T--) {
        nhap();
        Solve();
    }
    // auto TIME2 = chrono::steady_clock::now();
    // auto DIFF = TIME2 - TIME1;
    //cerr << "Time: " << fixed << setprecision(8) << chrono::duration<double>(DIFF).count() << "s.";
    return 0;
}