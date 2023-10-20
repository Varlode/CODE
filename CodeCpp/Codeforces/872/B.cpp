#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, k, a[N];
int f[21][N];

int get_min(int l, int r) {
    int k = log2(r-l+1);
    return min(f[k][l], f[k][r-(1<<k)+1]);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    if (k == 1) {
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) ans = min(ans, a[i]);
        cout << ans;
        return 0;
    }

    if (k == 3) {
        int ans = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) f[0][i] = a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i + 1 << (j-1) <= n; j++) {
            f[j][i] = min(f[j-1][i], f[j-1][i+1 << (j-1)]);
        }
    }

    int ans = -0x3f3f3f3f;
    for (int i = 1; i < n; i++)
        ans = max(ans, max(get_min(1, i), get_min(i+1, n)));
    cout << ans;

}