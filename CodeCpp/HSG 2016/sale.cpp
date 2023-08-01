#include<bits/stdc++.h>
using namespace std;

long long n, k, p;

int main() {
    freopen("sale.inp", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin >> n >> k >> p;
    cout << (long long) n/(k+1)*k*p+n%(k+1)*p;
}