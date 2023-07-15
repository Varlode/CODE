#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	int n, s, res = INT_MAX;
	cin >> n >> s;
	
	long long a[n];
	map<long long, int> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] += a[i - 1];
		m[a[i]] = i + 1;
		if (m[a[i] - s] != 0) res = min(res,  abs(m[a[i]] - m[a[i] - s]));
	}
	
	if (res == INT_MAX) res = -1;
	cout << res;
}

