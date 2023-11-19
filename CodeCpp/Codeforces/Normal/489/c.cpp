#include <bits/stdc++.h>
using namespace std;

int n, s;
string dpMx[101][901], dpMn[101][901];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> s;
    for (int i = 0; i <= 9; i++) dpMx[1][i] = dpMn[1][i] = char(i+'0');
    for (int i = 2; i <= n; i++) for (int j = 0; j <= s; j++) for (int k = 0; k <= 9; k++) 
    if (j > k) {
        dpMx[i][j] = max(dpMx[i][j], dpMx[i-1][j-k] + char(k+'0'));
        if (dpMn[i-1][j-k][0] != '0') {
            if (dpMn[i][j].size()) dpMn[i][j] = min(dpMn[i][j], dpMn[i-1][j-k]+char(k+'0'));
            else if (dpMn[i-1][j-k].size()) dpMn[i][j] = dpMn[i-1][j-k]+char(k+'0');
        }
    }
    if (dpMn[n][s] == "" || dpMx[n][s] == "") cout << -1 << ' ' << -1;
    else cout << dpMn[n][s] << ' ' << dpMx[n][s];
}