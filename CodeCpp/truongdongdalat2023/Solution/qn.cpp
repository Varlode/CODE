#include <bits/stdc++.h>
using namespace std;
#define task ""
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	int n; cin >> n;
	vector<int> res;
	res.push_back(0);
	res.push_back(1);
	for (int i = 1; i < n; ++i) {
        for (int j = (1 << i) - 1; j >= 0; --j) {
            res.push_back((1 << i) | res[j]);
        }
	}
	int rem; cin >> rem;
	for (int i = 0; i < (1 << n); ++i) if (res[i] == rem) {
        for (int j = i + 1; j < (1 << n); ++j) cout << res[j] << '\n';
        for (int j = 0; j <= i - 1; ++j) cout << res[j] << '\n';
	}

	return 0;
}
