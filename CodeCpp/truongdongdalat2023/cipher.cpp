#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    if (n&1) {
        cout << "AMBIGUOUS\n";
        return;
    }
    if (n == 2) {
        cout << s[1] << s[0] << '\n';
        return;
    }
    string ans = s;
    ans[1] = s[0];
    ans[n-2] = s[n-1];
    for (int i = 3; i <= n; i += 2) {
        if (s[i-1] < ans[i-2]) {
            ans[i] = ((s[i-1]-'A'+26) - (ans[i-2]-'A') + 'A');
        } else {
            ans[i] = ((s[i-1]-'A') - (ans[i-2]-'A') + 'A');
        }
    }
    for (int i = n-4; i >= 0; i -= 2) {
        if (s[i+1] < ans[i+2]) {
            ans[i] = ((s[i+1]-'A'+26) - (ans[i+2]-'A') + 'A');
        } else {
            ans[i] = ((s[i+1]-'A') - (ans[i+2]-'A') + 'A');
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cipher.inp", "r", stdin);
    freopen("cipher.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
}
