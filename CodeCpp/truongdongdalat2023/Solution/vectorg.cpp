#include <bits/stdc++.h>
using namespace std;
#define task "vectorg"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 1010;
int n, m, f[MAX];
vector<int> res[MAX];
pair<vector<int>, int> v[MAX];

bool ok(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < m; ++i) {
        if (a[i] > b[i])
            return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        v[i].second = i + 1;
        v[i].first.resize(m);
        for (int &j: v[i].first) cin >> j;
        sort(v[i].first.begin(), v[i].first.end());
    }
    int ans = 0;
    sort(v + 0, v + n + 0);
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (ok(v[j].first, v[i].first))
                f[i] = max(f[i], f[j] + 1);
        }
        res[f[i]].push_back(v[i].second);
        ans = max(ans, f[i]);
    }
    cout << ans << '\n';
    for (int i = 1; i <= ans; ++i) {
        cout << res[i].size() << ' ';
        sort(res[i].begin(), res[i].end());
        for (int &j: res[i]) cout << j << ' '; cout << '\n';
    }

	return 0;
}
