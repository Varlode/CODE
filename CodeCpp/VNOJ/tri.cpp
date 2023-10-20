#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int giaithua(int n) {
	if (n == 1 || n == 0) return 1;
	return (n % mod * giaithua(n - 1) % mod) % mod;
}

int main() {
	int n, t, a, b;
	cin >> n >> t >> a >> b;
	if ((t - (a + b * 2)) % 3 != 0 || t < (a + b * 2)) {
		cout << 0;
		return 0;
	}
	
	cout << (giaithua(t) % mod * giaithua(n - a - b) % mod) % mod;
	
}
