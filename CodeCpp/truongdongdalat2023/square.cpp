#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int hang[N], cot[N], dich_phai[N][N], dich_xuong[N][N];
char o[N][N];

void solve() {
    memset(o, 0, sizeof o);
    memset(dich_phai, 0, sizeof dich_phai);
    memset(hang, 0, sizeof hang);
    memset(dich_xuong, 0, sizeof dich_xuong);
    memset(cot, 0, sizeof cot);
    
    int n, cnt1, cnt2; cin >> n;
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) 
        cin >> o[i][j];

    cnt1 = cnt2 = 0;
    for (int i = 1; i <= n; i++) hang[i] = cot[i] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        hang[j] += (o[i][j] == 'X');
        cot[i] += (o[i][j] == 'X');
    }
    for (int i = 1; i <= n; i++) if ((hang[i] < 1 || 2 < hang[i]) || (cot[i] < 1 || 2 < cot[i])) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int rect = 0;

    // f la hang
    // g la cot
    dich_phai[n+1][1] = dich_xuong[1][n+1] = 0;
    cnt1 = 0;
    for (int i = 1; i <= n; i++) for (int j = n; j >= 1; j--) {
        if (o[i][j] == 'X') dich_phai[i][j] = j;
        else dich_phai[i][j] = dich_phai[i][j+1]; 
    }
    for (int i = n; i >= 1; i--) for (int j = 1; j <= n; j++) {
        if (o[i][j] == 'X') dich_xuong[i][j] = i;
        else dich_xuong[i][j] = dich_xuong[i+1][j]; 
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (o[i][j] == 'X' && dich_phai[i][j+1] && 
            dich_phai[dich_xuong[i+1][j]][j+1] == dich_phai[i][j+1] && 
            dich_xuong[i+1][dich_phai[i][j+1]] == dich_xuong[i+1][j]) rect++;
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
// if (o[i][j] == 'X' && dich_xuong[i+1][dich_phai[i][j+1]] && dich_xuong[i+1][fhang[i][j+1]] == fhang[i][j+1] && fhang[dich_xuong[i+1][j]][j+1] == dich_xuong[i+1][j]) rect++;