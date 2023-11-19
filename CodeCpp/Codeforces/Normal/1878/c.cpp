#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long n, k, x; cin >> n >> k >> x;
        string ans = "yes";
        if (n*(n+1)/2 - (n-k)*(n-k+1)/2 < x) ans = "no";
        if (k*(k+1)/2 > x) ans = "no";
        cout << ans << endl;
    }
}