#include<bits/stdc++.h>
using namespace std;

int T, n, m, a[100009], ans;

int check (int ok) {
    int pre = 1, cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[pre] >= ok) {
            pre = i;
            cnt++;
            if (cnt == m) break;
        }
    }
    return (cnt == m);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        fill(a, a + n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a, a + n + 1);
        ans = 0;
        int l = 0, r = a[n] - a[1];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                l = mid + 1;
                ans = max(ans, mid);
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}