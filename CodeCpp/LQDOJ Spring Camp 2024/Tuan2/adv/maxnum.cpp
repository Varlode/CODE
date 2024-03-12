#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n;
unsigned long long p[20];
pair<unsigned long long, unsigned long long> a[N];

void solve() {
    p[0] = 1;
    for (int i = 1; i <= 12; i++) p[i] = p[i-1]*10;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        int u = a[i].first, cnt = 0;
        while (u > 0) {
            u /= 10;
            cnt++;
        }
        a[i].second = cnt;
    }
    sort(a+1, a+1+n, [&] (auto x, auto y) {
        return x.first*p[y.second]+y.first > y.first*p[x.second]+x.first;
    });
    for (int i = 1; i <= n; i++) cout << a[i].first;
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
