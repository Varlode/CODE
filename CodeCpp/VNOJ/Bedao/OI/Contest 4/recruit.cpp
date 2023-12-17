/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, q;
int u[3][N], v[3][N];

void init(void) {
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> u[0][i] >> v[0][i] >> u[1][i] >> v[1][i] >> u[2][i] >> v[2][i];
        u[0][i]--; u[1][i]--; u[2][i]--;
    }
}

namespace one {

const int N = 21;

bool check(void) {
    return n <= 20;
}

void solve(void) {
    for (int mask = 0; mask < (1 << n); mask++) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            if (((mask >> u[0][i]) & 1) == v[0][i]) cnt++;
            if (((mask >> u[1][i]) & 1) == v[1][i]) cnt++;
            if (((mask >> u[2][i]) & 1) == v[2][i]) cnt++;
            if (cnt < 2) {
                res = 0;
                break;
            }
        }
        if (res) {
            for (int i = 0; i < n; i++) cout << ((mask >> i) & 1);
            return;
        }
    }
    cout << -1;
}

} // end namespace

namespace two {

bool check(void) {
    return q <= 20;
}

map<int, int> arr[3][N], ans;

void dfs(int u, map<int, int> &m) {
    int v = u+1;
    for (int i = 0; i < 3; i++) {
        int ok = 1;
        for (auto &p: arr[i][v]) {
            if (m.find(p.first) == m.end()) continue;
            if (m[p.first] != p.second) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            int cnt = 0;
            int mark[] = {0, 0, 0};
            for (auto &p: arr[i][v]) {
                cnt++;
                if (m.find(p.first) != m.end()) mark[cnt] = 1;
                else m[p.first] = p.second;
            }

            if (v < q) dfs(v, m);
            else ans = m;

            cnt = 0;
            for (auto &p: arr[i][v]) {
                cnt++;
                if (mark[cnt] == 0) m.erase(p.first);
            }
        }
        if (ans.size()) return;
    }
}

void solve(void) {
    // node 0 = (1, 2)
    // node 1 = (1, 3)
    // node 2 = (2, 3)
    for (int i = 1; i <= q; i++) {
        arr[0][i][u[0][i]] = v[0][i];
        arr[0][i][u[1][i]] = v[1][i];

        arr[1][i][u[0][i]] = v[0][i];
        arr[1][i][u[2][i]] = v[2][i];

        arr[2][i][u[1][i]] = v[1][i];
        arr[2][i][u[2][i]] = v[2][i];
    }

    for (int i = 0; i < 3; i++) {
        map<int, int> m;
        m = arr[1][i];
        dfs(1, m);
        if (ans.size()) break;
    }

    if (ans.size() == 0) {
        cout << -1;
        return;
    }

    vector<int> s(n, 0);
    for (auto &p: ans) s[p.first] = p.second;
    for (int i: s) cout << i;
}

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "recruit"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        init();
        if (one::check()) return one::solve(), 0;
        if (two::check()) return two::solve(), 0;
    }
}
