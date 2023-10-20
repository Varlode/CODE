#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, a[4][N];
int dp[8][N];

vector<vector<int>> state = 
{
    {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 0},
    {1, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 1}, {1, 0, 1, 0}
};

vector<vector<int>> match = 
{
    {0, 1, 2, 3, 4, 5, 6, 7}, {0, 2, 3, 4, 7}, {0, 1, 3, 4, 5, 6}, {0, 1, 2, 4, 6, 7},
    {0, 1, 2, 3, 5}, {0, 2, 4, 7}, {0, 2, 3}, {0, 1, 3, 5}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            dp[j][i] = -0x3f3f3f3f;
            int s = 0;
            for (int k = 0; k < 4; k++)
                s += a[k][i]*state[j][k];
            for (int k: match[j])
                dp[j][i] = max(dp[j][i], dp[k][i-1]);
            dp[j][i] = max(dp[j][i] + s, dp[j][i]);
            ans = max(ans, dp[j][i]);
        }
    }
    if (ans != 0)
        cout << ans;
    else {
        ans = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) for (int j = 0; j < 4; j++) ans = max(ans, a[j][i]);
        cout << ans;
    }
}