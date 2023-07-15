#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x, res;
    cin >> t;
    while (t--) {
    	cin >> n;
		int a[n + 1], res = -1;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> x;
			a[x]++;
			if (a[x] >= 3) res = x;
		};
		cout << res << endl;
	};
    return 0;
}
