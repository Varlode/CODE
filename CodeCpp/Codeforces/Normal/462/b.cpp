#include<bits/stdc++.h>
using namespace std;

int cnt[27];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        cnt[c-'A']++;
    }
    sort(cnt, cnt+26, greater<int>());
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        if (k >= cnt[i]) {
            ans += 1LL*cnt[i]*cnt[i];
            k -= cnt[i];
        } else {
            ans += 1LL*k*k;
            k -= k;
        }
    }
    cout << ans;
}