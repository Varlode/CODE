#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, k;
int a[N], mark[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1, cnt = 0, mx = 0;
    pair<int, int> ans = {0, 0};
    while (r <= n) {
        cnt += (mark[a[r]] == 0);
        mark[a[r]]++;
        while (cnt > k) {
            cnt -= (mark[a[l]] == 1);
            mark[a[l]]--;
            l++;
        }
        if (cnt <= k && mx < r-l+1) {
            mx = r-l+1;
            ans.first = l;
            ans.second = r;
        }
        r++;
    }
    cout << ans.first << ' ' << ans.second;
}