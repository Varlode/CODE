#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
int m, n, x, y;
long long ans;
long long a[maxN][maxN];

int dfs(int i, int j, int cnt) {
    if (i < 1 || m < i) return cnt-1;
    if (j < 1 || n < j) return cnt-1;
    if (a[i][j] == 1) return cnt-1;
    int t1, t2, t3, t4;
    a[i][j] = 1;
    t1 = dfs(i-1, j, cnt+1);
    t2 = dfs(i+1, j, cnt+1);
    t3 = dfs(i, j+1, cnt+1);
    t4 = dfs(i, j-1, cnt+1);
    a[i][j] = 0;
    return max(max(t1,t2),max(t3,t4));    
}

int main() {
    freopen("trongcay.inp", "r", stdin);
    freopen("trongcay.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> x >> y;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    ans = dfs(x, y, 1);
    cout << ans;
}