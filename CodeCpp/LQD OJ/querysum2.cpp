#include<bits/stdc++.h>
using namespace std;

int n, q;
long long bit[3][100009], a[100009];

long long get(int i, int p) {
    int idx = p;
    long long ans = 0;
    while (idx > 0) {
        ans += bit[i][idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int i, int u, long long x) {
    int idx = u;
    while (idx <= n) {
        bit[i][idx] += x;
        idx += (idx & (-idx));
    }
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) update(1, i, a[i] - a[i - 1]);
    for (int i = 1; i <= n; i++) update(2, i, (a[i] - a[i - 1]) * (n - i + 1));
    for (int i = 1; i <= q; i++) {
        int r; cin >> r;
        if (r == 1) {
            int u, v, x; cin >> u >> v >> x;
            update(1, u, x);
            update(1, v + 1, -x);
            update(2, u, x * (n - u + 1));
            update(2, v + 1, (-x) * (n - v));

        } else {
            int u, v; cin >> u >> v;
            cout << get(2, v) - get(1, v) * (n - v) - (get(2, u - 1) - get(1, u - 1) * (n - u + 1)) << endl;
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}   