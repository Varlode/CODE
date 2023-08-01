#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
int n, m, cnt = 0;
long long ans = 1e9+9;
int a[maxN][maxN], u[maxN], vstd[maxN];
vector<int> v[maxN];

void lt(int c) {
    u[c] = cnt;
    for (int i = 0; i < v[c].size(); i++) {
        if (u[v[c][i]] == 0) lt(v[c][i]);
    }
}

void dfs(int c, long long s, int k) {
    if (k == cnt) {
        ans = min(s, ans);
        return;
    }
    vstd[c] = 1;
    
    for (int i = 1; i <= cnt; i++) {
        if (vstd[i] == 0 && s + a[c][i] < ans) {
            dfs(i, s + a[c][i], k+1);
        }
    }
    vstd[c] = 0;
}

int main() {
    freopen("noimang.inp", "r", stdin);
    freopen("noimang.out", "w", stdout);
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (u[i] == 0) {
            cnt++;
            lt(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c; cin >> c;
            if (a[u[i]][u[j]] == 0) a[u[i]][u[j]] = c;
            else a[u[i]][u[j]] = min(a[u[i]][u[j]], c);
        }
    }
    if (cnt == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= cnt; i++)
        dfs(i, 0, 1);
    cout << ans;
}