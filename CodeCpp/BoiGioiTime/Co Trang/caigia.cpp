#include<bits/stdc++.h>
using namespace std;

const int N= 1e3+100;
int n, W, ans = -0x3f3f3f3f;
int a[N];

void recur(int id, int sum) {
    if (id > n) return;
    for (int i = 0; i <= 1; i++) {
        sum += a[id]*i;
        if (sum <= W) {
            ans = max(sum, ans);
            recur(id+1, sum);
        }
    }
}

main() {
    // freopen("caigia.inp", "r", stdin);
    // freopen("caigia.out", "w", stdout);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) cin >> a[i];
    recur(1, 0);
    cout << ans;
}  