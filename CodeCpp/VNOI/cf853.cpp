#include<bits/stdc++.h>
using namespace std;

const int maxN = 105, maxA = 1000009;
int a[maxN];

int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k) {
        a >>= 1;
        b >>= 1;
    }
    while ((a & 1) == 0)
        a >>= 1;
    do {
        while ((b & 1) == 0)
            b >>= 1;
        if (a > b)
            swap(a, b);
        b = (b - a);
    } while (b != 0);
    return a << k;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    string ans = "yes";
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
        if (gcd(a[j], a[i]) > 2) {
            ans = "no";
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
