#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k; cin >> n >> k;
    if (k >= 2*n) {cout << 0; return 0;}
    if (k <= n) {cout << (long long) (k - 1) / 2; return 0;}
    cout << (long long) (n - (k - n) + 1) / 2;
}
