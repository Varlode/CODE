#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, K;
long long ans;
map<int, int> m;

void solve() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a >= K) continue;
        m[a]++;
        if (a*a*1ll > K) continue;
        if (m.count(K-a*a)) ans += m[K - a*a];
    }
    cout << ans;
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
