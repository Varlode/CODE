#include<bits/stdc++.h>
using namespace std;

int x[209], n, k, a, b, ans = 1e9+9;

void dfs(int cur, int d, int cnt) {
    if (cnt > k) return;
    if (d >= ans) return;
    if (cur > n+1) return;

    if (cur == n+1) {
        ans = d;
        return;
    }
    for (int i = a; i <= b; i++) {
        dfs(cur+i, max(d, x[cur+i-1] - x[cur]), cnt+1);
    }
}

int main() {
    cin >> n >> k >> a >> b;
    for (int i = 1; i <= n; i++) 
        cin >> x[i];
    dfs(1, 0, 0);
    cout << ans << endl;
}