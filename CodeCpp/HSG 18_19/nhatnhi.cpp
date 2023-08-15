#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("nhatnhi.inp", "r", stdin);
    freopen("nhatnhi.out", "w", stdout);
    int n, max1 = -1e5, max2 = -1e5; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a > max1) {
            max2 = max1;
            max1 = a;
        }
    }
    cout << max1 << endl << max2;
}