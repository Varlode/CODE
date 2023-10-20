#include<bits/stdc++.h>
using namespace std;

const int maxM = 101, maxN = 101;
int a[maxM][maxN];

int main() {
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int j = 2; j <= n; j++)
    for (int i = 1; i <= m; i++)
        a[i][j] += max(a[i][j - 1], max(a[max(i - 1, 1)][j - 1], a[min(i + 1, m)][j - 1]));

    int ans = -10000001;
    for (int i = 1; i <= m; i++)
        ans = max(a[i][n], ans);
    cout << ans;
}
