#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int can = sqrt(n);
	if (can * can == n) {
		cout << can << " ";
		if (can % 2 == 0)
			cout << can * 2 - 1 << endl;
		else
			cout << 1 << endl;
	} else {
		cout << can + 1 << " ";
		if ((can + 1) % 2 == 0)
			cout << n - can * can << endl;
		else
			cout << (can + 1) * 2 - 1 - n + can * can << endl;
	}
	
	int r, c; cin >> r >> c;
	long long binh1 = (r - 1) * (r - 1), binh2 = r * r;
	if (r % 2 == 0) {
		cout << binh1 + c << endl;
	} else {
		cout << binh2 - c + 1 << endl;
	}
}
int main() {
	while (true) solve();
}
