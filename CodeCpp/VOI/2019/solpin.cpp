#include<bits/stdc++.h>
using namespace std;

const int N = 5*1e3;
int n, m, q;
long long a[N][N];

int pos_x, pos_y;

long long get(int u, int v, int s, int t) {
    return a[s][t] - a[s][v-1] - a[u-1][t] + a[u-1][v-1];
}

long long query(int x1, int y1, int x2, int y2) {
    x1 += pos_x; y1 += pos_y; x2 += pos_x; y2 += pos_y;
    return get(x1, y1, x2, y2);     
}

void update(int x, int y) {
    pos_x += x; pos_x %= m; if (pos_x == 0) pos_x = m;
    pos_y += y; pos_y %= n; if (pos_y == 0) pos_y = n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        a[i+m][j] = a[i][j+n] = a[i+m][j+n] = a[i][j];
    }  

    for (int i = 1; i <= 2*m; i++) for (int j = 1; j <= 2*n; j++) {
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    } 

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int p; cin >> p;
        if (p) {
            int u, v, s, t; cin >> u >> v >> s >> t;
            cout << query(u, v, s, t) << endl;
        } else {
            int x, y; cin >> y >> x;
            update(x, y);
        }
    }
}