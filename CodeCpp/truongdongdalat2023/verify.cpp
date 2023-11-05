#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[1010], l[1010], r[1010], b[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("verify.inp", "r", stdin);
    freopen("verify.out", "w", stdout);
    cin >> n >> q;   
    if (n > 10) {
        for (int i = 0; i < n; i++) cout << -1 << ' ';
        return 0;
    }
    for (int i = 1; i <= q; i++) cin >> l[i] >> r[i] >> a[i];
    for (int i = 0; i < n; i++) b[i] = i;
    do {
        int cont = 0;
        for (int i = 1; i <= q; i++) {
            int mn = 1e9;
            for (int j = l[i]; j <= r[i]; j++) mn = min(mn, b[j]);
            if (a[i] != mn) {
                cont = 1;
                break;
            }
        }
        if (cont) continue;
        for (int i = 0; i < n; i++) cout << b[i] << ' ';
        return 0;
    } while (next_permutation(b, b+n));
    for (int i = 0; i < n; i++) cout << -1 << ' ';
}