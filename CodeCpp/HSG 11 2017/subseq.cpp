#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
int n, k, ans = 0;
int a[maxN];

int main () {
    freopen("subseq.inp", "r", stdin);
    freopen("subseq.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % k == 0) a[i] = a[i - 1]+1;
        else a[i] = 0;
        ans = max(ans, a[i]);
    }
    cout << ans;
}