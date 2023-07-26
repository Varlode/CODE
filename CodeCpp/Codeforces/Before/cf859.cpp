#include<bits/stdc++.h>
using namespace std;

void solveA() {
	int a, b, c; cin >> a >> b >> c;
	if (a + b == c) cout << "+\n"; else cout << "-\n";
}

void solveB() {
	int n; cin >> n;
	int chan = 0, le = 0;
	for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2) le += x;
        else chan += x;
	}
	if (chan > le) cout << "yes\n"; else cout << "no\n";
}

void solveC() {
	int n; cin >> n;
	string s; cin >> s;
	int a[255];
	memset(a, -1, sizeof(a));
	bool ok = true;
	for (int i = 0; i < s.size(); i++) {
        if (a[s[i]] == -1) {
            a[s[i]] = i;
            continue;
        }
        if ((i - a[s[i]]) % 2 != 0) {
            ok = false;
            break;
        }

	}
	if (ok) cout << "yes\n"; else cout << "no\n";
}

void solveD() {
	int n, q; cin >> n >> q;
	int a[n + 1], s = 0;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        s += x % 2;
        a[i] = s;
	}
	for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k;
        k %= 2;
        if ((s - (a[r] - a[l - 1]) + k * (r - l + 1)) % 2 == 0) cout << "no\n";
        else cout << "yes\n";
	}
}

void solveF() {
	int n, m, i1, i2, j1, j2;
	cin >> n >> m >> i1 >> j1 >> i2 >> j2;
	string s; cin >> s;
	bool a[n + 5][m + 5][4][4]; memset(a, true, sizeof(a));
	int rar[4]; rar['D'] = 0; rar['U'] = 1, rar['L'] = 2; rar['R'] = 3;
	int cnt = 0;
	while (a[i1][j1][rar[s[0]]][rar[s[1]]]) {
        a[i1][j1][rar[s[0]]][rar[s[1]]] = false;
        //cout << i1 << " " << j1 << " " << s << "\n";
        if (s == "DR") {
            if (j2 >= j1 && i2 >= i1 && abs(j1 - j2) == abs(i1 - i2)) {
                cout << cnt << "\n";
                return;
            }
            if (n - i1 < m - j1) {
                j1 += (n - i1); i1 = n;
                s = "UR";
            }
            else if (n - i1 > m - j1) {
                i1 += (m - j1); j1 = m;
                s = "DL";
            } else {
                i1 = n; j1 = m;
                s = "UL";
            }
            cnt++;
            continue;
        }
        if (s == "UL") {
            if (j2 <= j1 && i2 <= i1 && abs(j1 - j2) == abs(i1 - i2)) {
                cout << cnt << "\n";
                return;
            }
            if (i1 - 1 < j1 - 1) {
                j1 -= i1 - 1 ;i1 = 1;
                s = "DL";
            }
            else if (i1 - 1 > j1 - 1) {
                i1 -= j1 - 1; j1 = 1;
                s = "UR";
            } else {
                i1 = 1; j1 = 1;
                s = "DR";
            }
            cnt++;
            continue;
        }
        if (s == "UR") {
            if (j2 >= j1 && i2 <= i1 && abs(j1 - j2) == abs(i1 - i2)) {
                cout << cnt << "\n";
                return;
            }
            if (i1 - 1 < m - j1) {
                j1 += i1 - 1; i1 = 1;
                s = "DR";
            }
            else if (i1 - 1 > m - j1) {
                i1 -= m - j1; j1 = m;
                s = "UL";
            } else {
                i1 = 1; j1 = m;
                s = "DL";
            }
            cnt++;
            continue;
        }
        if (s == "DL") {
            if (j2 <= j1 && i2 >= i1 && abs(j1 - j2) == abs(i1 - i2)) {
                cout << cnt << "\n";
                return;
            }
            if (n - i1 < j1 - 1) {
                j1 -= n - i1; i1 = n;
                s = "UL";
            }
            else if (n - i1 > j1 -1) {
                i1 += j1 - 1; j1 = 1;
                s = "DR";
            } else {
                i1 = n; j1 = 1;
                s = "UR";
            }
            cnt++;
            continue;
        }
	}
    cout << -1 << "\n";
    return;
}

void solveG1G2() {
	int n; cin >> n;
	int a[n];
	bool ok = true;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (a[0] != 1) ok = false;
	long long s = 1;
	if (ok) for (int i = 1; i < n; i++) {
        if (a[i] > s) {
            ok = false;
        }
        s += a[i];
	}
	if (ok) cout << "yes\n"; else cout << "no\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solveG1G2();
}
