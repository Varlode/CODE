#include <bits/stdc++.h>
using namespace std;

long long pow2[64], sum[64];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    
    pow2[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= 32; i++) {
        pow2[i] = pow2[i-1]*2;
        sum[i] += pow2[i] + sum[i-1];
    }
    long long n;
    while (t--) {
        cin >> n;
        int cnt = 0;
        while (pow2[cnt] < n) cnt++;
        if (pow2[cnt] > n) cnt--;
        cout << 1ll*n*(n+1)/2-2*sum[cnt] << '\n';
    }
}