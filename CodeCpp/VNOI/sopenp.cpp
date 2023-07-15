#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> ok;

void solve()
{
    int n, l, u; cin >> n >> l >> u;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ok[a[i]] = 0;
    }
    int i = 0, j = 0, ans = 0, cnt = 0, prei = 0, prej = 0;
    while (i <= j && j < n && i < n) {
        while (j < n && cnt < u && ok[a[j]] == 0) {
            cnt++; ok[a[j]] += 1;
            j++;
            
        }
        if (cnt >= l) ans += (cnt - l + 1) * (cnt - l + 2) / 2;
        if (i <= prej && prej - i <= u) ans -= (prej - i + 1 - l + 1) * (prej - i + 1 - l + 2) / 2; 
        
        if (cnt == u) {
            ok[a[i]] -= 1;
            i++;
            cnt--;
            continue;
        }
        while (i <= j && (ok[a[j]] == 1)) {
            ok[a[i]] -= 1;
            i++;
            cnt--;
        }
    }
    // if (l == 1) ans += n;
    cout << ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}   