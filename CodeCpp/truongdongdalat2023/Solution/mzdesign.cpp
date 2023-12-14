#include <bits/stdc++.h>
using namespace std;
#define task "mzdesign"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 111539786;
int nRow, nCol;
int nComp, nBan;
bool ban[110][15];
int dp[110][15][2 * 110 * 15];
#define prevDP(i, j, k) (j == 1 ? dp[i - 1][nCol][k] : dp[i][j - 1][k])

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> nRow >> nCol >> nComp >> nBan;
    for (int i = 1; i <= nBan; ++i) {
        int u, v; cin >> u >> v;
        ban[u][v] = true;
    }
    for (int i = 0; i <= nRow + 1; ++i) ban[i][0] = ban[i][nCol + 1] = true;
    for (int j = 0; j <= nCol + 1; ++j) ban[0][j] = ban[nRow + 1][j] = true;
    dp[0][nCol][nRow * nCol] = 1;
    for (int i = 1; i <= nRow; ++i) {
        for (int j = 1; j <= nCol; ++j) {
            for (int k = 1; k <= nRow * nCol; ++k) {
                if (ban[i][j] == true || (ban[i + 1][j] == true && ban[i][j + 1] == true)) {
                    add(dp[i][j][k], prevDP(i, j, k));
                    continue;
                }
                if (ban[i + 1][j] == true || ban[i][j + 1] == true) {
                    add(dp[i][j][k - 1], prevDP(i, j, k));
                    add(dp[i][j][k], prevDP(i, j, k));
                    continue;
                }
                add(dp[i][j][k - 1], 2LL * prevDP(i, j, k) % MOD);
                add(dp[i][j][k], prevDP(i, j, k));
            }
        }
    }
    cout << dp[nRow][nCol][nComp + nBan];

	return 0;
}
