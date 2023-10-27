#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> check = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 61, 73, 1662803};

ll pow2(ll a, ll b, ll mod) {
    if (a == 1 || b == 0) return 1;
    if (b == 1) return a;
    ll half = pow2(a, b/2, mod);
    if (b&1) return 1LL*half*half*a%mod;
    else return 1LL*half*half%mod;
}

bool isPrime(ll a, ll n, ll k, ll m) {
    ll mod = pow2(a, m, n);
    if (mod == 1 || mod == n-1) return true;
    for (int i = 1; i < k; i++) {
        mod = (mod*mod)%n;
        if (mod == n-1) return true;
    }
    return false;
}

bool millerrabin(ll n) {
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n < 11) return false;

    ll k = 0, m = n-1;
    while ((m&1) == 0) {
        m >>= 1;
        k++;
    }

    for (auto a: check) 
        if (a < n && !isPrime(a, n, k, m)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n_test; cin >> n_test;
    while (n_test--) {
        int n; cin >> n;
        cout << (millerrabin(n)? "YES": "NO") << endl;
    }
}