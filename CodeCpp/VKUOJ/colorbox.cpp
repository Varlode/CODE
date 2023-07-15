#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 7;
int a[maxN];
int ok[maxN], ok1[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, j, cnt = 0, cnt1 = 0; cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    i = 0; while (i < n) {
        if (ok[a[i]]) break;
        ok[a[i]]++;
        i++;
        cnt++;
    }
    int ans = n - cnt - cnt1;
    j = n - 1; while (j >= 0) {
        while (i >= 0 && ok[a[j]]) {
            ok[a[i]]--;
            i--;
            cnt--;
        }
        if (ok[a[j]]) break;
        cnt1++;
        ok[a[j]]++;
        ans = min(ans, n - cnt - cnt1);
        j--;

    }
    cout << ans;
}
