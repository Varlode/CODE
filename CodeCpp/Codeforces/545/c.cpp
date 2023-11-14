#include <bits/stdc++.h>
using namespace std;

const int N = 101010;
int n;
long long l[N], m[N], r[N], x[N], h[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n;
    x[0] = -1e10; x[n+1] = 1e10;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> h[i];
    for (int i = 1; i <= n; i++) {
        if (x[i-1] < x[i] - h[i]) l[i] = max(m[i-1], l[i-1]) + 1;
        if (x[i-1] + h[i-1] < x[i] - h[i]) l[i] = max(l[i], r[i-1]+1);
        m[i] = r[i] = max({m[i-1], l[i-1], r[i-1]});
        if (x[i] + h[i] < x[i+1]) r[i]++;
    }
    cout << max({m[n], r[n], l[n]});
}