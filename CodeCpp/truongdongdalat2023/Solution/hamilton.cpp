#include <bits/stdc++.h>
using namespace std;
#define task "hamilton"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int BLK = 1000;
int n;
vector<pair<int, int>> pos[BLK + 10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        pos[y / BLK].push_back(make_pair(x, i));
    }
    int type = 0;
    for (int i = 0; i <= BLK; ++i) if (pos[i].size()) {
        if (type == 0) sort(all(pos[i])); else sort(rall(pos[i]));
        for (pair<int, int> &tmp: pos[i]) cout << tmp.second << ' '; type ^= 1;
    }


	return 0;
}
