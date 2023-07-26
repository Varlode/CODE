#include<bits/stdc++.h>
using namespace std;

int n, q;
long long bit[100005];

long long get(int p) {
    int idx = p;
    long long ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }
    for (int i = 1; i <= q; i++) {
        int r, x, y; cin >> r >> x >> y;
        if (r == 1) update(x, y);
        else cout << get(y) - get(x - 1) << endl;
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