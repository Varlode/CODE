#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, h; cin >> n >> h;
    int c[2][n / 2];
	map<int, int> count;
    for (int i = 0; i < n; i++) cin >> c[i % 2][i / 2];
	n /= 2; sort(c[0], c[0] + n); sort(c[1], c[1] + n);
	
	int res = INT_MAX;
	for (int i = 0; i < h; i++) {
		int s = n - (upper_bound(c[0], c[0] + n, i) - c[0]);
		s += n - (upper_bound(c[1], c[1] + n, h - i - 1) - c[1]);
		++count[s];
		res = min(res, s);
	}
	cout << res << " " << count[res];
}

