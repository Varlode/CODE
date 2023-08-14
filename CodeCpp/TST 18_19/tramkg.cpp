#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("tramkg.inp", "r", stdin);
    freopen("tramkg.out", "w", stdout);
    int n; cin >> n;
    int tmp = n%4;
    if (tmp == 0) cout << n+1 << ' ' << 0;
    if (tmp == 1) cout << 0 << ' ' << n+1;
    if (tmp == 2) cout << -n-1 << ' ' << 0;
    if (tmp == 3) cout << 0 << ' ' << -n-1;
    cout << endl << (n+1)*159;
}