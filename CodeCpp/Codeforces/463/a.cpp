#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, s; cin >> n >> s;
    int max_x = 0, max_y = -1;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (x*100+y > s*100) continue;
        if (y == 0) {
            max_y = max(max_y, 0);
            continue;
        }
        if (x >= max_x) max_y = max(max_y, 100-y);
    }
    cout << max_y;
}