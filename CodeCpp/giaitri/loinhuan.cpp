#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	int n, res = 0;
	cin >> n;
	
	long long a[n + 1];
	map<long long, int> m;
	a[-1] = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = a[i - 1] + a[i];		
		if (m[a[i]] == 0 and a[i] != 0) {
			m[a[i]] = i + 1;
		} else
		res = max(res, i + 1 - m[a[i]]);
	}

	if (res == 0) res = -1;
	cout << res;
}

