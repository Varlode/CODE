#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int n, k;
int a[N], pref[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    int mx = 1e9, ans = 0;
    for (int i = k; i <= n; i++) {
        if (mx > pref[i] - pref[i-k]) {
            mx = pref[i] - pref[i-k];
            ans = i-k+1;            
        }
    }
    cout << ans;
}