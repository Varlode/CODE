#include<bits/stdc++.h>
using namespace std;

void solve1() {
    int a, b; cin >> a >> b;
    int cana = sqrt(a), canb = sqrt(b);
    if (cana * cana == a) {
        for (int i = cana; i < canb; i++)
            cout << i * i << " ";
        cout << canb * canb;
    } else {
        for (int i = cana + 1; i < canb; i++)
            cout << i * i << " ";
        cout << canb * canb;
    }
}

bool snt(int n) {
    if (n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

void solve2() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << snt(3*x*(x - 1) + 1) << "\n";
    }
}

void solve3() {
    long long n; cin >> n;
    long long sum = n * (n + 1) / 2;
    long long ans = 4 * sum + 1;
    cout << ans;
}
const int maxN = 1e5+5;

vector<int> topo, a[maxN];
long long d[maxN], visited[maxN];

void dfs(int u) {
    visited[u] = true;
    for (int x: a[u]) {
        if (!visited[x])
            dfs(x);
    }
    topo.push_back(u);
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
    d[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(topo.begin(), topo.end());
    for (int x: topo) {
        for (int y: a[x]) {
            d[y] += d[x];
        }
    }
    cout << d[n];
}

int main() {
    solve();
}
