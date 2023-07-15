#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i ++) cin >> a[i];
    int l = 0, r = n - 1;

    while (l < r && a[l] + a[r] != x) {
        if (a[l] + a[r] < x) l++;
        else r--;
    }

    if (l < r && a[l] + a[r] == x) cout << l + 1 << " " << r + 1;
    else cout << "No solution";
}