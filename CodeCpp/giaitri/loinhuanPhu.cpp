#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("loinhuan.inp", "r", stdin);
	
	int n;
	cin >> n;
	long a[n], s = 0, x;
	int res = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		s += x;
		a[i] = s;
		for (int j = i - 1; i >= 0; i--) {
			if (a[i] == a[j]) res = max(res, i - j);
		} 
	}
	cout << res;
}
