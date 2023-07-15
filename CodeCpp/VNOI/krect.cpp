#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    int m, n, k, res = 0;
    cin >> m >> n >> k;
    int count[26][m + 1][n + 1];
    memset(count, 0 , sizeof(count));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char a; cin >> a;
            for (int l = 0; l < 26; l++) count[l][i][j] = count[l][i][j - 1] + count [l][i - 1][j] - count[l][i - 1][j - 1];
            count[a - 65][i][j]++;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int z = i; z <= m; z++) {
                for (int t = j; t <= n; t++) {
                    int krect = 0;
                    for (int l = 0; l < 26; l++)
                        if (count[l][z][t] - count[l][z][j - 1] - count [l][i - 1][t] + count[l][i - 1][j - 1] > 0) {
							krect++;
						} 
                    if (krect == k) {
						res++;
					}
                }
            }
        }
    }
    
    cout << res;
}
