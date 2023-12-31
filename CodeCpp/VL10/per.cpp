#include<bits/stdc++.h>
using namespace std;

/* NHAP
    sub 1: a[i] <= 1001, n <= 1001, q <= 1001;
    -> keu gi lam do, danh dau a[i] trong mang mark

    sub 2: x = u && y = v
    -> dem so luong so xuat hien 2 lan cua moi doan
    q(i, i) == 1
    q(l, r) == 2
*/

const int N = 1e5+1;
int n, q, a[N], b[N];
int x[N], y[N], u[N], v[N];

void init(void) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= q; i++)
        cin >> x[i] >> y[i] >> u[i] >> v[i];
}

struct ONE {

bool check(void) {
    return n <= 1001 && q <= 1001;
}

int mark[1001];

void solve(void) {
    for (int qi = 1; qi <= q; qi++) {
        memset(mark, 0, sizeof mark);
        int res = 0;
        for (int i = x[qi]; i <= y[qi]; i++) mark[a[i]] = 1;
        for (int i = u[qi]; i <= v[qi]; i++) res += mark[b[i]] == 1;
        cout << res << '\n';
    }
}

} one;

struct TWO {

struct QUERY {
    int l, r, val, type;

    QUERY () {}
    QUERY (int _l, int _r, int _val, int _type):
        l(_l), r(_r), val(_val), type(_type) {}

};
vector<QUERY> query;

struct BIT {
    int fen[N];

    void upd(int i, int v) {
        for (; i < N; i += i & (-i)) fen[i] += v;
    }

    int get(int i) {
        int ret = 0;
        for (; i > 0; i -= i & (-i)) ret += fen[i];
        return ret;
    }
} bit;

bool check(void) {
    for (int i = 1; i <= q; i++)
        if (x[i] != u[i] || y[i] != v[i]) return false;
    return true;
}

int mark[N], ans[N];

void solve(void) {
    for (int i = 1; i <= n; i++) {
        query.push_back(QUERY(i, i, a[i], 1));
        query.push_back(QUERY(i, i, b[i], 1));
    }
    for (int i = 1; i <= q; i++)
        query.push_back(QUERY(x[i], y[i], i, 2));
    sort(query.begin(), query.end(), [&] (QUERY a, QUERY b){
        return a.r < b.r || (a.r == b.r && a.type < b.type);
    });

    for (QUERY &qi: query) {
        int l = qi.l, r = qi.r, val = qi.val, type = qi.type;
        if (type == 1) {
            if (mark[val] > 0) bit.upd(mark[val], 1);
            mark[val] = l;
        }
        else ans[val] = bit.get(r) - bit.get(l-1);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

} two;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define task "per"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    init();
    if (one.check()) return one.solve(), 0;
    if (two.check()) return two.solve(), 0;
}
