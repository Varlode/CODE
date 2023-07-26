#include<bits/stdc++.h>
using namespace std;

int check(int a, b[]) {
	for 
}

void solve() {
	int n, w, h; cin>> n >> w >> h;
	int x = a[0] - w, y = a[0] + w;
	while (x < y) {
		int m = x + (y - x + 1) / 2;
		if check(m, )
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}

//void solve() {
//	int n; cin >> n;
//	int saw = 0, sab = 0, sbw = 0, sbb = 0, cnt = 1, s = 1, sw = 0;
//	while (n >= s) {
//		if (cnt == 2) {
//			sw = !sw;
//			cnt = 0;
//		}
//		if (sw == 0) {
//			saw += s / 2 + s % 2;
//			sab += s / 2;
//		} else {
//			sbw += s / 2;
//			sbb += s / 2 + s % 2;
//		}
//		n -= s;
//		s++; cnt++;
//	}
//	if (cnt == 2) {
//		sw = !sw;
//		cnt = 0;
//	}
//	if (sw == 0) {
//		saw += n / 2 + n % 2;
//		sab += n / 2;
//	} else {
//		sbw += n / 2;
//		sbb += n / 2 + n % 2;
//	}
//	cout << saw << " " << sab << " " << sbw << " " << sbb << endl;
//}
