#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, m; 
int bit[2][N], a[N], t[N];

void upd(int i, int u, int v) {
    int idx = u;
    while (idx <= N) {
        bit[i][idx] += v;
        idx += idx&(-idx);
    }
}

int get(int i, int u) {
    int idx = u, ans = 0;
    while (idx > 0) {
        ans += bit[i][idx];
        idx -= idx&(-idx);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> val;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
        val.push_back(t[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 1; i <= n; i++) a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
    for (int i = 1; i <= m; i++) t[i] = lower_bound(val.begin(), val.end(), t[i]) - val.begin() + 1;
    for (int i = 1; i <= n; i++) upd(0, a[i], 1);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        cout << get(0, n) - get(0, t[i]-1) - (get(1, n) - get(1, t[i]-1)) << endl;
        upd(1, t[i], 1);
    }
}