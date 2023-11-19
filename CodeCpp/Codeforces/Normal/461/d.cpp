#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6+100;
int f[N], g[N], cntf[N], cntg[N];
int n, a[N];

vector<int> val;

int bit[N];

void zip() {
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
    }
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

main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    zip();

    for (int i = 1; i <= n; i++) f[i] = ++cntf[a[i]];
    for (int i = n; i >= 1; i--) g[i] = ++cntg[a[i]];

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