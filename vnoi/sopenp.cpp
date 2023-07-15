#include<bits/stdc++.h>
using namespace std;

const int maxN = (1 << 20) + 5, maxX = 1 << 31;
int a[maxN];
map<int, bool> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, u; cin >> n >> l >> u;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (m[a[i]] == 1)
            a[i] = a[i - 1];
        else {
            a[i] = a[i - 1] + 1;
            m[a[i]] = 1;
        }
    }
    int ans = 0;
    vector<int> v(a, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] >= l)
        ans += (upper_bound(v.begin(), v.begin() + i, a[i] - l + 1)
        - lower_bound(v.begin(), v.begin() + i, a[i] - u + 1)) + 1;
    }

    cout << ans;
}
