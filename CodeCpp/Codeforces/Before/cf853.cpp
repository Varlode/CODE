#include<bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	cout << min(a * n - n / m * n, b * n) << enl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
