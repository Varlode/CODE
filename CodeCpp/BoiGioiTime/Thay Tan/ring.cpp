#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    freopen("ring.inp", "r", stdin);
    freopen("ring.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        string s1, s2;
        for (int j = i; 2*(j-i) < n; j++) {
            s1.push_back(s[j%n]);
        }
        for (int j = i-1; j >= i-n/2; j--) {
            int k = (j < 0)? n+j: j;
            s2.push_back(s[k]);
        }
        // cout << s1 << ' ' << s2 << endl;
        if (s1 == s2) ans++;
    }
    cout << ans;
}