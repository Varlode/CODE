#include <bits/stdc++.h>
using namespace std;
#define task "C"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r) {
    return l + 1LL * rd() % (r - l + 1) * rd() % (r - l + 1);
}

const long long INF = 1e18 + 7;
const int MAX = 100010;
int n, q;
int lab[MAX];
pair<long long, int> f[MAX];

int find_set(int v) {
    return lab[v] < 0 ? v : lab[v] = find_set(lab[v]);
}

bool union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return false;
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v]; lab[v] = u;
    return true;
}

struct event {
    int a, b, delta;

    event(int _a = 0, int _b = 0, int _delta = 0) {
        a = _a;
        b = _b;
        delta = _delta;
    }

    bool operator< (const event &other) const {
        return delta < other.delta;
    }
};
vector<event> events[MAX];

struct node {
    long long fi; int u;
    long long se; int v;

    node(long long _fi = 0, int _u = 0, long long _se = INF, int _v = -1) {
        fi = _fi;
        se = _se;
        u = _u;
        v = _v;
    }
};

long long lz[MAX << 2];
node st[MAX << 2];

node combine(const node &lf, const node &rg) {
    node res;
    res.fi = lf.fi; res.u = lf.u;
    res.se = rg.fi; res.v = rg.u;
    if (res.fi > res.se) {
        swap(res.fi, res.se);
        swap(res.u, res.v);
    }
    long long se = INF; int v = -1;
    if (res.u != res.v) {
        se = res.se;
        v = res.v;
    }
    if (lf.v != -1 && res.u != lf.v) {
        if (se > lf.se) {
            se = lf.se;
            v = lf.v;
        }
    }
    if (rg.v != -1 && res.u != rg.v) {
        if (se > rg.se) {
            se = rg.se;
            v = rg.v;
        }
    }
    if (v != -1) {
        res.se = se;
        res.v = v;
    }
    return res;
}

void build(int id, int l, int r) {
    lz[id] = 0;
    if (l == r) st[id] = node(0, find_set(l));
    else {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = combine(st[id << 1], st[id << 1 | 1]);
    }
}

void push(int id) {
    if (lz[id] != 0) {
        lz[id << 1] += lz[id];
        st[id << 1].fi += lz[id];
        st[id << 1].se += lz[id];
        lz[id << 1 | 1] += lz[id];
        st[id << 1 | 1].fi += lz[id];
        st[id << 1 | 1].se += lz[id];
        lz[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, int delta) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        st[id].fi += delta;
        st[id].se += delta;
        lz[id] += delta;
        return;
    }
    int mid = l + r >> 1; push(id);
    update(id << 1, l, mid, u, v, delta);
    update(id << 1 | 1, mid + 1, r, u, v, delta);
    st[id] = combine(st[id << 1], st[id << 1 | 1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        int a, b, c, d, w;
        cin >> a >> b >> c >> d >> w;
        events[a].push_back(event(c, d, +w)); events[b + 1].push_back(event(c, d, -w));
        events[c].push_back(event(a, b, +w)); events[d + 1].push_back(event(a, b, -w));
    }
    memset(lab, -1, sizeof lab);
    long long res = 0;
    int nComp = n;
    while (nComp > 1) {
        build(1, 1, n);
        memset(f, 0x3f, sizeof f);
        for (int i = 1; i <= n; ++i) {
            int ii = find_set(i);
            for (event &tmp: events[i]) {
                int a = tmp.a, b = tmp.b, delta = tmp.delta;
                update(1, 1, n, a, b, delta);
            }
            node tmp = st[1];
            int uu = tmp.u;
            int vv = tmp.v;
            if (ii != uu) {
                f[ii] = min(f[ii], make_pair(tmp.fi, uu));
                f[uu] = min(f[uu], make_pair(tmp.fi, ii));
            }
            if (ii != vv) {
                f[ii] = min(f[ii], make_pair(tmp.se, vv));
                f[vv] = min(f[vv], make_pair(tmp.se, ii));
            }
        }
        for (int i = 1; i <= n; ++i) if (f[i].first < INF) {
            int j = f[i].second;
            if (j <= n) {
                if (union_set(i, j)) {
                    res += f[i].first;
                    --nComp;
                }
            }
        }
    }
    cout << res;

	return 0;
}
