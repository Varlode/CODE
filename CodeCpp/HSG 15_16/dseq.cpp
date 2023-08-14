#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
long long maxD[maxN], minD[maxN], maxC[maxN], minC[maxN], sumC, sumD;
int n, a[maxN];
long long ans = 0;

int main() {
    freopen("dseq.inp", "r", stdin);
    freopen("dseq.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n+1; i++) {
        maxD[i] = maxC[i] = -1e9-9;
        minD[i] = minC[i] = 1e9+9;
    }
    for (int i = 1; i <= n; i++) {
        sumD += a[i];
        maxD[i] = max(sumD, maxD[i - 1]);
        minD[i] = min(sumD, minD[i - 1]);
    }
    for (int i = n; i >= 1; i--) {
        sumC += a[i];
        maxC[i] = max(sumC, maxC[i + 1]);
        minC[i] = min(sumC, minC[i + 1]);
    }
    for (int i = 1; i < n; i++) {
        ans = max(max(abs(maxD[i] - minC[i+1]), abs(minD[i] - maxC[i+1])),ans);
    }
    cout << ans;
}