#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define TASK "TASK"

const int cs = 2e5 + 7;
const int maxN = 2e3 + 7;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }

int k,n,s;
int a[maxN][maxN];
int Prefix[maxN][maxN];
ll dp[maxN][maxN];

void nhap() {
    cin >> k >> n >> s;
    for (int i =1;i <= s;i++) {
        int x,y;
        cin >> x >> y;
        a[x][y]++;
    }
    for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++)
        Prefix[i][j] = Prefix[i - 1][j] + Prefix[i][j - 1] - Prefix[i - 1][j - 1] + a[i][j];
}

int GetSum(int u,int v,int x,int y) {
    return Prefix[x][y] - Prefix[x][v - 1] - Prefix[u - 1][y] + Prefix[u - 1][v - 1];
}

void Solve() {

    for (int i = 0;i <= n;i++) dp[i][0] = dp[0][i] = 0;

    for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) {
        if (k == 1) dp[i][j] = min(i,j);
        else dp[i][j] = max(i,j);
    }

    for (int u = 1;u <= n;u++) for (int v = 1;v <= n;v++) for (int x = 1;x <= u;x++) for (int y = 1; y <= v;y++) {
        ll tmp = dp[u][y - 1] + dp[x - 1][v] - dp[x - 1][y - 1];
        if (GetSum(x,y,u,v) > 0) {
            if (k == 1) tmp += min(abs(u - x + 1), abs(v - y + 1));
            else tmp += max(abs(u - x + 1), abs(v - y + 1));
        }
        minimize(dp[u][v], tmp);
    }
    cout << dp[n][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // if(fopen(TASK".inp", "r")) {
    //     freopen(TASK".inp", "r", stdin);
    //     freopen(TASK".out", "w", stdout);
    // }
    int T = 1;
    while (T--) {
        nhap();
        Solve();
    }
    return 0;
}
