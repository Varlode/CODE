#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;
int n, a[11][N];
int cntRow[11];

void dfs(int d) {
    if (d > n) return;
    dfs(d+1);
    cin >> a[d][cntRow[d]++];
    dfs(d+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "obilazak"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> n;
    dfs(1);
    for (int i = 1; i <= n; i++) { 
       for (int j = 1; j < cntRow[i]; j++) cout << a[i][j] << ' '; cout << a[i][cntRow[i]];
       if (i < n) cout << endl;
    }
}