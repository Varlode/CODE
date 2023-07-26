#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	int n, s, x, res = INT_MAX, sum = 0;
	cin >> n >> s;
	int a[n + 1], j = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum <= 0) {
			sum = 0;
			j = i + 1;
		} else {
			if (sum < s) continue;
			if (sum >= s) {
				while (sum - a[j] >= s and j < i) {
					sum -= a[j];
					j++;
				}
				res = min(res, i - j + 1);
			}
		}
	}
	if (res == INT_MAX) res = -1;
	cout << res;
}
