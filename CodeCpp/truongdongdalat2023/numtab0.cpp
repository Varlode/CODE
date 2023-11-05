#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

const int N = 101;

int n, timer;
int a[N][N], b[N][N], vis[N], assigned[N], row[N];
vector<int> adj[N];

// assigned la mang danh dau dinh ben Y noi voi dinh nao do ben Xs

void swapRow(int x, int y) {
    for (int i = 1; i <= n; i++) swap(b[x][i], b[y][i]);
}

bool visit(int u) {
    if (vis[u] == timer) return false;
    vis[u] = timer;
    for (int v: adj[u]) {
        if (!assigned[v] || visit(assigned[v])) {
            assigned[v] = u;
            return true;
        }
    }
    return false;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 1) adj[j].push_back(i);
        b[i][j] = i;
        // b la danh dau o nao o hang nao
    }

    // tim xem co '1' o hang nao ko ghep duoc khong
    // dong thoi cung da tim ra cap ghep cuc dai voi ham visit
    for (int i = 1; i <= n; i++) {
        timer = i;
        if (!visit(i)) {
            cout << -1 << endl;
            return 0;
        }
    }

    // row[j] = i la hang i va hang j can doi cho nhau
    for (int i = 1; i <= n; i++) row[assigned[i]] = i;

    vector<pi> ans;
    for (int i = 1; i <= n; i++) {
        int pos;
        // xet cac hang j trung voi mang row[i] o tren, 
        // tuc la hai hang nay se doi voi nhau
        for (int j = 1; j <= n; j++) {
            if (b[j][i] == row[i]) {
                pos = j;
                break;
                // ham for nay 100% break vi da loai tru o tren
            }
        }
        if (i != pos) {
            swapRow(i, pos);
            ans.push_back({i, pos});
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y]: ans) cout << 1 << ' ' << x << ' ' << y << endl;
}