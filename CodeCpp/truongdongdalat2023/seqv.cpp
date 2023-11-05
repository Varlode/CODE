#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N], pref[N];

int get(int i, int j) {return pref[j] - pref[i-1];}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] += pref[i-1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        map<int, int> cnt;
        for (int j = i; j <= n; j++) {
            cnt[a[j]] ^= 1;
            if (cnt[a[j]] == 0) cnt.erase(a[j]);
            if (get(i, j) > 0 && cnt.empty()) ans++;
        }
    }
    cout << ans;
}       