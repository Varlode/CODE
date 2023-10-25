#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>

const int N = 50050;
int n, k, par[N], sz[N][550];
vector<ii> e;

int find(int u) {
    return u == par[u]? u: par[u] = find(par[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    par[u] = par[v];
}

int main() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e.push_back({u, v});
    }

}