#include<bits/stdc++.h>
using namespace std;

int a[4];

int main() {
    freopen("rectangle.inp", "r", stdin);
    freopen("rectangle.out", "w", stdout);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a+4);
    cout << (long long) a[0]*a[2];
}