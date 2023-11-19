#include <bits/stdc++.h>
using namespace std;

const int N = 101010;
int n, a[N], k[N], vis[N];
long long ans[N];
struct DSU {
    using T = long long;
    T lab[N];
    void build() {
        for (int i = 1; i <= n; i++) lab[i] = -a[i];
    }
    int find(int u) {
        return lab[u] <= 0? u: lab[u] = find(lab[u]);
    }
    bool join(T u, T v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (lab[u] > lab[v]) swap(u, v);
            lab[u] += lab[v];
            lab[v] = u;
            return true;
        }
        return false;
    }
    
} dsu;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dsu.build();
    for (int i = 1; i <= n; i++) cin >> k[i];
    long long mx = 0;
    for (int i = n; i >= 1; i--) {
        ans[i] = mx;
        if (vis[k[i]-1]) dsu.join(k[i], k[i]-1);
        if (vis[k[i]+1]) dsu.join(k[i], k[i]+1);
        vis[k[i]] = 1;
        mx = max({mx, -dsu.lab[dsu.find(k[i])]});
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}