#include <bits/stdc++.h>
using namespace std;
#define task "planet"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7;
const int MAX = 100010;
int n;
int c[MAX];
int R[MAX];
int pf[MAX];
int dp[MAX];
int oldValue;
int gcd[17][MAX];

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int getGCD(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return __gcd(gcd[k][l], gcd[k][r - (1 << k) + 1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        gcd[0][i] = c[i];
    }
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            gcd[j][i] = __gcd(gcd[j - 1][i], gcd[j - 1][i + (1 << j - 1)]);
    }
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j < n && getGCD(i, j + 1) > 1) ++j;
        R[i] = j;
    }
    int allGCD = getGCD(1, n), res = allGCD > 1;
    for (int j = n; j >= 1; --j) {
        if (oldValue != c[1]) {
            for (int i = 1; i <= j; ++i) {
                pf[i] = 0;
                dp[i] = 0;
            }
            for (int i = 1; i <= j; ++i) {
                if (__gcd(c[1], getGCD(1, i)) == 1) break;
                R[1] = i;
            }
            dp[0] = 1;
            for (int i = 1; i <= j; ++i) {
                add(pf[i], dp[i - 1]); add(pf[R[i] + 1], MOD - dp[i - 1]);
                add(pf[i], pf[i - 1]); add(dp[i], pf[i]);
            }
            oldValue = c[1];
        }
        add(res, dp[j]); add(res, MOD - (allGCD > 1));
        c[1] = __gcd(c[1], c[j]);
        if (c[1] == 1) break;
    }
    cout << res;
	return 0;
}
