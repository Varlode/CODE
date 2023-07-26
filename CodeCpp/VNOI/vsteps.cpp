#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 6;
int a[maxN], f[maxN];
int mod = 14062008;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    int j = 0;
    if (a[j] == 1) {
        f[1] = 0;
        j++;
    } else f[1] = 1;
    if (a[j] == 2) {
        f[2] = 0;
        j++;
    } else f[2] = 1;
    for (int i = 3; i <= n; i++) {
        if (a[j] == i) {
            f[i] = 0;
            j++;
        } else f[i] = (f[i - 2] % mod + f[i - 1] % mod) % mod;
    }
    cout << f[n];
}
