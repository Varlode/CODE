#include<bits/stdc++.h>
using namespace std;

int n, k;
int b[1010], a[1010], dp[1010];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n; i++) {
        a[i] = (lower_bound(b, b+n, a[i]) - b)/k;
        dp[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    cout << n-ans;
}
