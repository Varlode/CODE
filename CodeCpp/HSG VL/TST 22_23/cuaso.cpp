#include<bits/stdc++.h>
using namespace std;

int n, p, m, ans, a[3009][3009];

void update(int x1, int y1, int x2, int y2) {
    a[x1][y1] += 1;
    a[x2+1][y1] += -1;
    a[x1][y2+1] += -1;
    a[x2+1][y2+1] += 1;
}

int main() {
    cin >> n >> m >> p;
    while (p--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        update(x1+1, y1+1, x2+1, y2+1);
    }
    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= m+1; j++) {
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
        }
    }
    
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            ans += a[i][j] > 0;
    cout << ans << endl;
}