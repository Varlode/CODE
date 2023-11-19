#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "shell"
    if (fopen(TASK".in", "r")) {
        freopen(TASK".in", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int ans = 0;
    int n; cin >> n;
    int a[n], b[n], g[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i];
    }
    for (int i = 1; i <= 3; i++) {
        int point = 0;
        int flag[4] = {0, 0, 0, 0};
        flag[i] = 1;
        for (int j = 0; j < n; j++) {
            swap(flag[a[j]], flag[b[j]]);
            point += flag[g[j]];
        }
        ans = max(ans, point);
    }
    cout << ans;
}