#include<bits/stdc++.h>
using namespace std;

int N, K, dsK[509][509], vstd[509], ans = 1e9+9;

void dfs(int dinh, int sum, int cnt) {
    vstd[dinh] = 1;
    if (sum == K) {
        ans = min(ans, cnt);
    }
    for (int i = 1; i <= N; i++) {
        if (sum + dsK[dinh][i] <= K && dsK[dinh][i] != 0 && vstd[i] == 0 && cnt + 1 < ans) {
            dfs(i, sum + dsK[dinh][i], cnt + 1);
        }
    }
    vstd[dinh] = 0;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y >> dsK[x][y];
        dsK[y][x] = dsK[x][y];
    }
    for (int i = 1; i <= N; i++) {
        dfs(i, 0, 0);
    }
    (ans == 1e9+9)? cout << -1 : cout << ans;
}