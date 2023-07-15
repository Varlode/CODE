#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int m, n, k, res = 0;
    cin >> m >> n >> k;
    int count[26][m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            char a; cin >> a;
            count[a - 65][i][j]++;
        }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < m; k++) {
                for (int t = j; t < n; t++) {
                    int krect = 0;
                    for (int l = 0; l < 26; l++) 
                        if (count[l][k][t] - count[l][i][j] > 0) krect++;
                    if (krect = k) res++;
                }
            }
        }
    }
    cout << res;
    return 0;
}
