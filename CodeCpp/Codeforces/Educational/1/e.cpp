#include <bits/stdc++.h>
using namespace std;

const int N = 31, K = 51;
int dp[N][N][K];

int f(int a, int b, int c) {
    if (dp[a][b][c] || a*b == c || c == 0) return dp[a][b][c];
    int ans = 1e9;
    for (int i = 1; i <= a-i; i++) for (int j = 0; j <= c; j++) 
        ans = min(ans, b*b+f(i, b, c-j)+f(a-i, b, j));
    for (int i = 1; i <= b-i; i++) for (int j = 0; j <= c; j++) 
        ans = min(ans, a*a+f(a, i, c-j)+f(a, b-i, j));
    return dp[a][b][c] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        cout << f(n, m, k) << '\n';
    }
}