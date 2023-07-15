#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sr, sl, a[n];
	int dix[n + 2], din[n + 2], djx[n + 2], djn[n + 2];
	dix[0] = INT_MIN, din[0] = INT_MAX;
	djx[n + 1] = INT_MIN, djn[n + 1] = INT_MAX;
	int res = 0;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sl = sl + a[i];
		dix[i] = max(dix[i - 1], sl);
		din[i] = min(din[i - 1], sl);
	}
	for (int i = n; i >= 1; i--){
		sr = sr + a[i];
		djx[i] = max(djx[i + 1], sr);
		djn[i] = min(djn[i + 1], sr);
	}
	for (int i = 1; i < n; i++) {
		res = max(res, max(abs(dix[i] - djn[i + 1]), abs(din[i] - djx[i + 1])));
	}
	cout << res << endl << INT_MIN << endl << INT_MAX;
}
