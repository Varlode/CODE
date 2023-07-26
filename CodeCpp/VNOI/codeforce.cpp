#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, c; cin >> n >> c;
		int a[n], tmp, m = INT_MAX, res = 0;
		
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] + i + 1 < m) {
				tmp = i;
				m = a[i] + i + 1;
			}
		}
		
		if (c >= m) {
			c -= m;
			res = 1;
		}
		
		sort(a, a + n);
		int i = 0;
		while (c >= a[i] && i < n) {
			if (i == tmp) {
				i++;
				continue;
			}
			c -= a[i];
			res++;
			i++;
		}
		cout << res << endl;
	}
}

//string ss = "codeforces";
//	int t; cin >> t;
//	while (t--) {
//		char c; cin >> c;
//		for (int i = 0; i < ss.size(); i++) {
//			if (c == ss[i]) {
//				cout << "YES" << endl;
//				break;
//			}
//			if (i == ss.size() - 1) cout << "NO" << endl;
//		}
//	}

//int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		string s; cin >> s;
//		int x = 0, y = 0;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == 'L') x -= 1;
//			if (s[i] == 'R') x += 1;
//			if (s[i] == 'U') y += 1;
//			if (s[i] == 'D') y -= 1;
//			if (x == 1 && y == 1) {
//				cout << "YES" << endl;
//				break;
//			}
//			if (i == n - 1) cout << "NO" << endl;
//		}
//	}

//int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		string s; cin >> s;
//		if (n <= 1) {
//			cout << n << endl;
//			continue;	
//		}
//		int l = 0, r = n - 1, res = n;
//		
//		while (l < r) {
//			if (s[l] != s[r]) {
//				l++;
//				r--;
//				res -= 2;
//			} else break;
//		}
//		cout << res << endl;
//	}

//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		string s; cin >> s;
//		if (n <= 2) {
//			cout << n << endl;
//			continue;
//		}
//		
//		bool l[256], r[256];
//		int cntl[n + 2], cntr[n + 2];
//		
//		for (int i = 0; i <= 256; i++) {
//			l[i] = false;
//			r[i] = false;
//		}
//		
//		for (int i = 0; i < n + 2; i++) {
//			cntl[i] = 0;
//			cntr[i] = 0;
//		}
//		
//		cntl[0] = 1; l[int(s[0])] = true;
//		cntr[n - 1] = 1; r[int(s[n - 1])] = true;
//		
//		for (int i = 1; i < n; i++) {
//			cntl[i] = cntl[i - 1];
//			if (!l[int(s[i])]) {
//				l[int(s[i])] = true;
//				cntl[i]++;
//			}
//		}
//		
//		for (int i = n - 2; i >= 0; i--) {
//			cntr[i] = cntr[i + 1];
//			if (!r[int(s[i])]) {
//				r[int(s[i])] = true;
//				cntr[i]++;
//			}
//		}
//		int res = 0;
//		for (int i = 0; i < n; i++) res = max(res, cntl[i] + cntr[i + 1]);
//		cout << res << endl; 
//	}

//int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		int neg = 0, m = INT_MAX; long long res = 0;
//		int a[n]; for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			if (a[i] < 0) {
//				a[i] = -a[i];
//				neg++;
//			}
//			res += a[i];
//			m = min(m, a[i]);
//		}
//		
//		if (neg % 2 == 0) cout << res << endl;
//		else cout << res - 2 * m << endl;
//	}

//int convert(int n) {
//	int res = 0;
//	while (n >= 10) {
//		res += n % 10;
//		n /= 10;
//	}
//	return res + n;
//}
//int t; cin >> t;
//	while (t--) {
//		int n, q; cin >> n >> q;
//		int a[n], cv[n];
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			cv[i] = 0;	
//		}
//		while (q--) {
//			int cm; cin >> cm;
//			if (cm == 1) {
//				int l, r; cin >> l >> r;
//				for (int i = l - 1; i < r; i++) cv[i]++;
//			}
//			if (cm == 2) {
//				int x; cin >> x; x--;
//				while (cv[x] > 0) {
//					a[x] = convert(a[x]);
//					cv[x]--;
//				}
//				cout << a[x] << endl;
//			}
//		}
//	}
