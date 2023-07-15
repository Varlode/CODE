#include<bits/stdc++.h>
using namespace std;

int n, q;
long long bit[200009];

long long get(int p) {
    int idx = p;
    long long ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int l, int v) {
    int idx = l;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

void updateRange(int l, int r, int v) {
    update(l, v);
    update(r + 1, -v);
}

void solve()
{
    cin >> n >> q;
    int pre = 0, curr;
    for (int i = 1; i <= n; i++) {
        cin >> curr;
        update(i, curr - pre);
        pre = curr;
    }
    for (int i = 1; i <= q; i++) {
        int r; cin >> r;
        if (r == 1) {
            int a, b, u; cin >> a >> b >> u;
            updateRange(a, b, u);
        } else {
            int p; cin >> p;
            cout << get(p) << endl;
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