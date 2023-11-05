#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ppi pair<int, pi>
#define fi first 
#define se second 

const int N = 200200;
int n, q;
int a[N], b[N];
int st[N*4];

unordered_map<int, int> mark;

void update(int i, int l, int r, int u, int v) {
    if (u < l || r < u) return;
    if (l==r) { 
        st[i] += v;
        return;
    }
    int m = l+(r-l)/2;
    update(i*2, l, m, u, v);
    update(i*2+1, m+1, n, u, v);
    st[i] = max(st[i*2], st[i*2+1]);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASk"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mark[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        update(1, 1, n, (i > mark[b[i]]? i-mark[b[i]]: i+n-mark[b[i]]), 1);
    }
    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        update(1, 1, n, (x > mark[b[x]]? x-mark[b[x]]: x+n-mark[b[x]]), -1);
        update(1, 1, n, (y > mark[b[y]]? y-mark[b[y]]: y+n-mark[b[y]]), -1);
        swap(b[x], b[y]);
        update(1, 1, n, (x > mark[b[x]]? x-mark[b[x]]: x+n-mark[b[x]]), 1);
        update(1, 1, n, (y > mark[b[y]]? y-mark[b[y]]: y+n-mark[b[y]]), 1);
        cout << st[1] << endl;
    }
} 