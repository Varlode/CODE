#include<bits/stdc++.h>
using namespace std;

const int N = 5000;
int n, a[N][N];
long long f[N], g[N];
long long ans_l[2], ans_r[2], ans[2];

void maximize(int i, int l, int r) {
    if (f[l+r-1]+g[n-l+r]-a[l][r] >= ans[i]) {
        ans[i] = f[l+r-1]+g[n-l+r]-a[l][r];
        ans_l[i] = l;
        ans_r[i] = r;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i+j-1] = a[i][j] + f[i+j-1];
            g[n-i+j] = a[i][j] + g[n-i+j];
        }   
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            maximize((i+j)&1, i, j);
        }   
    }
    cout << ans[0] + ans[1] << endl;
    cout << ans_l[0] << ' ' << ans_r[0] << ' ' << ans_l[1] << ' ' << ans_r[1];
}
