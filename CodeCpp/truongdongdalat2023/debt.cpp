#include <bits/stdc++.h>
using namespace std;

int n, L, R, K;
int a[101], dpL[101][101][2501], dpR[101][101][2501]; 

void init() {
    cin >> n >> L >> R >> K;
    K = min(n*n/4, K);
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve() {
    int sum = 0, ans;
    for (int i = L; i <= R; i++) sum += a[i];
    for (int i = 1; i < L; i++) for (int j = L; j <= R; j++) for (int k = 0; k <= K; k++) {
        dpL[i][j][k] = min({dpL[i][j][k], dpL[i-1][j][k], dpL[i][j-1][k], dpL[i][j][k-1]});
        if (k >= (j-i)) dpL[i][j][k] = min(dpL[i][j][k], dpL[i-1][j-1][k-(j-i)] - a[j] + a[i]);
    }
    for (int i = n; i > R; i--) for (int j = R; j >= L; j--) for (int k = 0; k <= K; k++) {
        dpR[i][j][k] = min({dpR[i][j][k], dpR[i+1][j][k], dpR[i][j+1][k], dpR[i][j][k-1]});
        if (k >= (i-j)) dpR[i][j][k] = min(dpR[i][j][k], dpR[i+1][j+1][k-(i-j)] - a[j] + a[i]);
    }
    ans = min(dpL[L-1][R][K], dpR[R+1][L][K]);
    for (int i = L; i < R; i++) for (int k = 0; k <= K; k++)
        ans = min(ans, dpL[L-1][i][k]+dpR[R+1][i+1][K-k]);
    cout << sum+ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "debt"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    init();
    solve();
}   