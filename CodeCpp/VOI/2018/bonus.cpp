#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, k, r, p;
long long ans;
long long a[N][N];

struct rect {
    int x1, x2, y1, y2;
    rect(int u, int v, int x, int y) {
        x1=u; y1=v; x2=x; y2=y;
    }
};

rect intersect(rect u, rect v) {
    rect ans = rect(1, 1, n, n);
    ans.x1 = max(u.x1, v.x1);
    ans.x2 = min(u.x2, v.x2);
    ans.y1 = max(u.y1, v.y1);
    ans.y2 = min(u.y2, v.y2);
    return ans;
}

long long get(rect u) {
    if (u.x2 < u.x1 || u.y2 < u.y1) return 0;
    return a[u.x2][u.y2]-a[u.x2][u.y1-1]-a[u.x1-1][u.y2]+a[u.x1-1][u.y1-1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> r >> p;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        a[i][j] += a[i][j-1]+a[i-1][j]-a[i-1][j-1];
    }

    ans = -1e9;
    for (int i = 1; i <= k; i++) {
        long long sum = 0;
        vector<rect> rs;
        for (int i = 1; i <= p; i++) {
            int x, y; cin >> x >> y;
            rs.push_back(rect(x, y, x+r-1, y+r-1));
        }
        for (int i = 1; i < (1 << p); i++) { //00001 -> 11111
            int sign = (__builtin_popcount(i)&1)? 1: -1;
            rect area = rect(1, 1, n, n);

            for (int j = 0; j < p; j++) if (i&(1 << j)) { // 00001 00010 00100 01000 10000
                area = intersect(area, rs[j]);
            }

            sum += sign*get(area)*1LL;
        }

        ans = max(ans, sum);
    }
    cout << ans << endl;
}