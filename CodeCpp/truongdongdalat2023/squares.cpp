#include <bits/stdc++.h>
using namespace std;

#define int long long

int check(int n) {
    int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (n > 0) {
        if (cnt[n%10]++) return false;
        n/=10;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int k; cin >> k;
    if (k > (int) 610) cout << -1;
    else {
        int cnt = 0;
        for (int i = 1; i <= (int) 99381; i++) {
            cnt += check(1LL*i*i);;
            if (cnt == k) {
                cout << 1LL*i*i;
                return 0;
            }
        }
        cout << -1;
    }
}