#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int f[N], g[N], ff[N][N], gg[N][N];
char a[N][N];

void solve() {
    memset(a, 0, sizeof a);
    memset(ff, 0, sizeof ff);
    memset(f, 0, sizeof f);
    memset(gg, 0, sizeof gg);
    memset(g, 0, sizeof g);
    
    int n, cnt1, cnt2; cin >> n;
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) 
        cin >> a[i][j];

    cnt1 = cnt2 = 0;
    for (int i = 1; i <= n; i++) f[i] = g[i] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        f[j] += (a[i][j] == 'X');
        g[i] += (a[i][j] == 'X');
    }
    for (int i = 1; i <= n; i++) if ((f[i] < 1 || 2 < f[i]) || (g[i] < 1 || 2 < g[i])) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int rect = 0;

    // f la hang
    // g la cot
    ff[n+1][1] = gg[1][n+1] = 0;
    cnt1 = 0;
    for (int i = 1; i <= n; i++) for (int j = n; j >= 1; j--) {
        if (a[i][j] == 'X') ff[i][j] = j;
        else ff[i][j] = ff[i][j+1]; 
    }
    for (int i = n; i >= 1; i--) for (int j = 1; j <= n; j++) {
        if (a[i][j] == 'X') gg[i][j] = i;
        else gg[i][j] = gg[i+1][j]; 
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (a[i][j] == 'X' && ff[i][j+1] 
            && ff[gg[i+1][j]][j+1] == ff[i][j+1] 
            && gg[i+1][ff[i][j+1]] == gg[i+1][j]) rect++;
    }
    if (rect == n/2) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("square.inp", "r", stdin);
    freopen("square.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();   
}
// if (a[i][j] == 'X' && gg[i+1][ff[i][j+1]] && gg[i+1][ff[i][j+1]] == ff[i][j+1] && ff[gg[i+1][j]][j+1] == gg[i+1][j]) rect++;