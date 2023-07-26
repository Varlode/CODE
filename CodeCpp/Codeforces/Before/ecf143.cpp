#include<bits/stdc++.h>
using namespace std;

void solve1() {
	int n, m; cin >> n >> m;
	string ns, ms; cin >> ns >> ms;
	string rev = "";
	for (int i = m - 1; i >= 0; i--)
		rev = rev + ms[i];
	ms = ns + rev;
	int cnt = 0;
	int i = 1; while (i < n + m) {
		if (ms[i] == ms[i - 1]) cnt++;
		i++;
	}
	if (cnt > 1) {
		cout << "no" << endl;
	} else cout << "yes" << endl;
}

void solve() {
	int n, k; cin >> n >> k;
	int x, y, cnt = 0;
	
	vector<int> a(101, 0), b(101, 0), c(101, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (k < x || y < k) continue;
		a[x] += 1;
		b[++y] -= 1;
		cnt++;
	}
	if (cnt == 0) {
		cout << "no" << endl;
		return;
	}
	
	int m = 0;
	for (int i = 1; i <= 50; i++) {
		a[i] += a[i - 1] + b[i];
		c[a[i]]++;
		m = max(m, a[i]);
	}
	
	if (m == a[k] && c[a[k]] == 1) cout << "yes" << endl;
	else cout << "no" << endl; 
}
int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
