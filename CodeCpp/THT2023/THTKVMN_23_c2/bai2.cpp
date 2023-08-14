#include<bits/stdc++.h>
#define ll long long;
#define ld long double;
using namespace std;

int bit[1][100009], a[100009];
int n, q, ok = false;

int get(int i, int u) {
    int idx = u, ans = 0;
    while (idx > 0) {
        ans += bit[i][idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int i, int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[i][idx] += v;
        idx += (idx & (-idx));
    }
}

bool find(int i, int l, int r, int k) {
    unordered_map<int, int> m;
    int sum = 0;
    for (int x = l; x <= r; x++) {
        int tmp = get(0, x);
        sum += tmp;
        if (m[k - tmp] != 0) {
            cout << m[tmp] << ' ' << x << endl;
            return true;
        }
        m[sum] = x;
        
    }
    return false;
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(0, i, a[i]);
    } 
    for (int i = 1; i <= q; i++) {
        int r; cin >> r;
        if (r == 1) {
            int u, v; cin >> u >> v;
            update(0, u, a[u] - v);
            a[u] = v;
        } else {
            int l, r, k; cin >> l >> r >> k;
            if (find(0, l, r, k) == false) cout << -1 << endl;
        }
    }    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}