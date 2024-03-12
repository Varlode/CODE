#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, a[N];
long long ans;
unordered_map<int, int> m;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }

    sort(a+1, a+n);

    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i-1]) continue;
        long long u = 2, cnt = m[a[i]];
        while (u <= 1073741824) {
            if (u > a[i]) {
                if (a[i] == u-a[i])
                    ans += 1ll*cnt*(cnt-1)/2;
                else ans += 1ll*cnt*m[u-a[i]];
            }
            u += u & (-u);
        }
        m[a[i]] = 0;
    }
    cout << ans;
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    solve();
}
