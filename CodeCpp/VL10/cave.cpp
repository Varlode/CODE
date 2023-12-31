#include<bits/stdc++.h>
using namespace std;

/* NHAP
    sub 1, 2: duyet trau tu cac diem vao neu gap diem ra thi cap nhat ket qua
    sub 3: dung for neu 2 3 thi cap nhat dap an
*/

const int N = 1e5+1;
int n, a[N], type[N], u[N], v[N];
long long pref[N];
vector<int> adj[N];

void init(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> type[i];
    for (int i = 1; i < n; ++i) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
}

struct ONE {

bool check(void) {
    return n <= 2001;
}

long long ans = -1e18;

void dfs(int u, int p, long long sum) {
    if (type[u] == 2 || type[u] == 3) ans = max(ans, sum);
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, sum+a[v]);
    }
}

void solve(void) {
    for (int i = 1; i <= n; i++) {
        if (type[i] == 1 || type[i] == 3) dfs(i, 0, a[i]);
    }
    cout << ans;
}

} one;

struct TWO {


bool check(void) {
    for (int i = 1; i < n; i++) if (u[i] != i || v[i] != i+1) return false;
    return true;
}

int mark[4] = {0, 0, 0, 0};

void solve(void) {
    long long ans = -1e18, mn = 1e18;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i];
        if (type[i] == 1) {
            mn = min(mn, pref[i-1]);
            mark[1] = 1;
        }
        if (type[i] == 2 && (mark[1] || mark[3])) {
            ans = max(ans, pref[i]-mn);
        }
        if (type[i] == 3) {
            mn = min(mn, pref[i-1]);
            ans = max(ans, pref[i]-mn);
            mark[3] = 1;
        }
    }
    cout << ans;
}

} two;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define task "cave"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    init();
    if (one.check()) return one.solve(), 0;
    if (two.check()) return two.solve(), 0;
}
