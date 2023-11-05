#include <bits/stdc++.h>
using namespace std;

int pow2[26];
int dp[10];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    pow2[0] = 1;
    dp[0] = 0;
    for (int i = 1; i <= 25; i++) pow2[i] = pow2[i-1]*2;
    for (int i = 1; i <= n; i++) for (int k = 1; k <= 26; k++) {
        dp[i]
    }
}