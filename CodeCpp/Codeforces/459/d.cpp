#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int f[N], g[N];
int n, a[N];

unordered_map<int, int> m;

int bit[N];

void zip() {
    
}

void update(int u, int v) {
    int idx = u;
    while (idx > 0) {
        bit[idx] += v;
        idx -= (idx & (-idx));
    }
}

int get(int u) {
    int idx = u, ans = 0;
    while (idx <= n) {
        ans += bit[idx];
        idx += (idx & (-idx));
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    m.clear();
    for (int i = 1; i <= n; i++) f[i] = ++m[a[i]];
    m.clear();
    for (int i = n; i >= 1; i--) g[i] = ++m[a[i]];

    int ans = 0;
    // for (int i = 1; i <= n; i++) cout << f[i] << ' '; cout << endl;
    // for (int i = 1; i <= n; i++) cout << g[i] << ' '; cout << endl;

    for (int i = 1; i <= n; i++) {
        ans += get(g[i] + 1);
        // cout << get(g[i] + 1) < < ' ';
        update(f[i], 1);
    }
    cout << ans;
}