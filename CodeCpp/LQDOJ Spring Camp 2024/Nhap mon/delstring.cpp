#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
int n, k;
char a[N];
int cnt[300], ans = 1;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) cnt[j] = 0;
        int res = 1, diff = 0, one = 1;

        int l = 1;
        while (a[l] != i && l <= n) l++;
        if (l > n) continue;

        int r = l+1;
        while (r <= n) {
            while (a[r] != i && r <= n) {
                if (cnt[a[r]] == 0) diff++;
                cnt[a[r]]++;
                r++;
            }
            if (r > n) break;
            one++;
            if (diff > k) {
                l++;
                one--;
            }
            while (diff > k) {
                while (a[l] != i && l <= n) {
                    cnt[a[l]]--;
                    if (cnt[a[l]] == 0) diff--;
                    l++;
                }
                if (diff > k) {
                    l++;
                    one--;
                }
            }
            r++;
            res = max(res, one);
        }
        ans = max(ans, res);
    }
    cout << ans;
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    solve();
}
