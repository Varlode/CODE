#include<bits/stdc++.h>
using namespace std;

void init() {
	
}

void solve1() {
	int n; cin >> n;
	int t[n]; for (int i = 0; i < n; i++) cin >> t[i];
	int res = 0;
	int i = 1;
	while (i < n) {
		while (t[i] > t[i - 1] && i < n) i++;
		while (t[i] < t[i - 1] && i < n) i++;
		
		res++;
	}
	cout << res;
	
}

void solve2() {
	int n; cin >> n;
	int a[n], s[n], x = 0; 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x += a[i];
		s[i] = x;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] == 0 && a[j] == 0) {
				if (j == i + 1) cout << 1 << endl;
				else cout << s[j] - s[i] << endl;
			}
}

void solve3() {
	int n; cin >> n;
	int c[n]; for (int i = 0; i < n; i++) cin >> c[i];
	sort(c, c + n);
	
	int p; cin >> p;
	while (p--) {
		int k; cin >> k;
		int x = 0, y = n - 1;
		
		while (x < y) {
			int m = (x + y) / 2 + 1;
			if (k < c[m]) {y = m - 1;}
			else {x = m + 1;}
		}
		cout << x << endl;
	}
}

void solve4() {
	int n; cin >> n;
	
	int cnt = 0, res = 0;
	while (n--) {
		int a; cin >> a;
		int ok3 = 0, ok2 = 0;
		ok2 = (a % 2 == 0);
		while (a > 0) {
			ok3 += a % 10;
			a /= 10;
		}
		ok3 = (ok3 % 3 == 0);
		if (ok2 && ok3) cnt++;
		else {
			res = max(res, cnt);
			cnt = 0;
		}
	}
	cout << res;
}

void solve5() {
	int n, w; cin >> n >> w;
	int m[n], t[n];
	for (int i = 1; i <= n; i++) cin >> m[i] >> t[i];
	int mt[n + 1][w + 1];
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= w; j++)
			mt[i][j] = 0;
	
	int res = 0;
	
	for (int i = 1; i <= n; i++) {
		mt[i][m[i]] = t[i];
		for (int j = 1; j <= w; j++) {
			mt[i][j] = max(mt[i][j], mt[i - 1][j]);
			if (j >= m[i] && mt[i - 1][j - m[i]] > 0) mt[i][j] = max(mt[i][j], mt[i - 1][j - m[i]] + mt[i][m[i]]);
			res = max(res, mt[i][j]);
		}
	}
	cout << res;
}

int m, n, x, y, u ,v;
int cot[] = {0, 1, 0, -1}, hang[] = {-1, 0, 1, 0};
int a[1001][1001], b[1001][1001];

void dijkstra(int y, int x) {
	for (int i = 0; i < 4; i++) {
		if ((y + hang[i] > m) || (y + hang[i] < 1) || (x + cot[i] > n) || (x + cot[i] < 1) || a[y + hang[i]][x + hang[i]]) continue;
		if (b[y + hang[i]][x + hang[i]] == 0) b[y + hang[i]][x + hang[i]] = b[x][y] + 1;
		else b[y + hang[i]][x + hang[i]] = min(b[y + hang[i]][x + hang[i]], b[x][y] + 1);
	}
	a[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		if ((y + hang[i] > m) || (y + hang[i] < 1) || (x + cot[i] > n) || (x + cot[i] < 1)) continue;
		dijkstra(y + hang[i], x + cot[i]);
	}
	
}

void solve() {
	cin >> m >> n >> x >> y >> u >> v;
	
	b[x][y] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	dijkstra(x, y);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
}
int main() {
	solve();	
}
