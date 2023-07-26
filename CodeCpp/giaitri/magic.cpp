#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool can;
	int res = n - 1;
	for (int k = 1; k <= n/2; k++) { 
		can = 1;
		for (int j = 0; j < k; j++) { 
			for (int i = 0; i < n/k; i++) {
				if (a[j] != a[i*k+j]) can = 0;
				if (!can) break;
			}
			if (!can) break;
		}
		if (can) res = min(res, k);
	}
	cout << res;
}
