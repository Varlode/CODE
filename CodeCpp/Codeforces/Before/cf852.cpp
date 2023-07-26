#include<bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	cout << (long long) (n / (m + 1)) * min((long long) m * a, (long long) (m + 1) * b) + (long long) min(a, b) * (n % (m + 1)) << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
