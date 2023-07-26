#include<bits/stdc++.h>
using namespace std;

int a[1007];

void solve1() {
	int n; cin >> n;
	a[-1] = 0;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[i] = a[i - 1];
		if (x == 2) a[i]++;
	}
	int ans = n;
	
	for (int i = 0; i < n; i++) {
		if (a[n - 1] - a[i] == a[i]) ans = min(i, ans);
	}
	if (ans == n) {cout << "-1" << endl; return;}
	cout << ans + 1 << endl;
}

int intToInt(int n) {
	int ans = 0;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
void solve() {
	int n1; cin >> n1;
	int n2 = 0, cnt = 10;
	int tmp1 = intToInt(n1), tmp2 = intToInt(n2);
	while (tmp1 - tmp2 > 1 && cnt < 1000000000 && tmp1 > tmp2) {
		cout << n1 << " " << n2 << " " << tmp1 << " " << tmp2 << " " << cnt << endl;
		if (n1 % cnt <= (tmp1 - tmp2) / 2 * cnt / 10) {
			n2 += n1 % cnt;
			n1 -= n1 % cnt;
		} else {
			n2 += (tmp1 - tmp2) / 2 * cnt / 10;
			n1 -= (tmp1 - tmp2) / 2 * cnt / 10;
		}
		cnt *= 10;
		tmp1 = intToInt(n1), tmp2 = intToInt(n2);
	}
	cout << n1 << " " << n2 << endl;
}
int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;	
}
