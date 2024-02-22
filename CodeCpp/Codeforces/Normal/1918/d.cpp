#include <bits/stdc++.h>
using namespace std;

const
    int N           = 1e5+10;
    long long inf   = 1e12;
int n, a[N];
long long pref[N];

struct SEGMENT {
    long long val[N*4];

    void build(int i, int l, int r) {
        if (l > r) return;
        if (l == r) {
            val[i] = inf;
            return;
        }
        int m = (l + r) >> 1;
        build(i*2, l, m);
        build(i*2+1, m+1, r);
        val[i] = min(val[i*2], val[i*2+1]);
    }

    void upd(int i, int l, int r, int u, long long v) {
        if (u < l || r < u) return;
        if (l == r) {
            val[i] = v;
            return;
        }
        int m = (l + r) >> 1;
        upd(i*2, l, m, u, v);
        upd(i*2+1, m+1, r, u, v);
        val[i] = min(val[i*2], val[i*2+1]);
    }

    long long get(int i, int l, int r, int u, int v) {
        if (r < u || v < l) return inf;
        if (u <= l && r <= v) return val[i];
        int m = (l + r) >> 1;
        return min(
            get(i*2, l, m, u, v),
            get(i*2+1, m+1, r, u, v)
        );
    }

    inline void upd(int u, long long v) {upd(1, 0, n+1, u, v);}
    inline long long get(int u, int v) {return get(1, 0, n+1, u, v);}

} myTree;

bool check(long long x) {
    myTree.build(1, 0, n+1);
    myTree.upd(0, 0);

    for (int i = 1; i <= n+1; i++) {
        int l = 0, r = i-1, res = -1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (pref[i-1] - pref[m] <= x) {
                res = m;
                r = m-1;
            }
            else l = m+1;
        }
        if (res == -1) return 0;
        long long mn = myTree.get(res, i);
        myTree.upd(i, mn + a[i]);
    }
    return myTree.get(n+1, n+1) <= x;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    a[0] = a[n+1] = pref[0] = 0;
    for (int i = 1; i <= n+1; i++) pref[i] = pref[i-1]+a[i];

    long long l = 0, r = inf, ans = inf;
    while (l <= r) {
        long long m = (l + r) >> 1;
        if (check(m)) {
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
