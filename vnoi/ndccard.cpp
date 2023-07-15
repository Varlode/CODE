#include<bits/stdc++.h>
using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0;

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++) {
            res = max(res, a[i] + a[j] + a[lower_bound(a + j, a + n, m - a[i] + a[j]) - a]);
            cout << a[i] << " " << a[j] << " " << lower_bound(a + j, a + n, m - a[i] + a[j]) - a << endl;;
        }
    cout << res;
}
