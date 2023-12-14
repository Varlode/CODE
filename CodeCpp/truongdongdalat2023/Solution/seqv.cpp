#include <bits/stdc++.h>
using namespace std;
#define task "C"

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r) {
    assert(l <= r);
    return l + (1LL * rd() * rd() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

const int MAX = 200020;
int n;
int a[MAX];
int id[MAX];
vector<int> tmp;

namespace subtask2 {
	int have[2020];

	long long solve(void) {
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			long long sum = 0; int cntOdd = 0;
			memset(have, 0, sizeof have);
			for (int j = i; j <= n; ++j) {
				cntOdd += have[id[j]] == 0;
				cntOdd -= have[id[j]] == 1;
				have[id[j]] ^= 1; sum += a[j];
				ans += cntOdd == 0 && sum > 0;
			}
		}
		return ans;
	}
}

namespace subtask3 {
	vector<int> pos[1 << 21];
	long long pf[MAX];
	int bit[MAX];

	void update(int id, int delta) {
		for (; id <= n; id += id & -id)
			bit[id] += delta;
	}

	int get(int id) {
		int res = 0;
		for (; id > 0; id -= id & -id)
			res += bit[id];
		return  res;
	}

	bool ok(void) {
		for (int i = 1; i <= n; ++i) {
			if (abs(a[i]) > 10)
				return false;
		}
		return true;
	}

	long long solve(void) {
		long long ans = 0;
		pos[0].push_back(0);
		for (int i = 1, mask = 0; i <= n; ++i) {
			mask ^= 1 << id[i];
			pos[mask].push_back(i);
			pf[i] = pf[i - 1] + a[i];
		}
		#define ID(value) (lower_bound(v.begin(), v.end(), value) - v.begin() + 1)
		for (int mask = 0; mask < (1 << 21); ++mask) if (pos[mask].size() > 1) {
			vector<long long> v;			for (int id: pos[mask]) v.push_back(pf[id]);
			sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
			for (int id: pos[mask]) {
				int posPf = ID(pf[id]);
				ans += get(posPf - 1);
				update(posPf, +1);
			}
			for (int id: pos[mask]) {
				int posPf = ID(pf[id]);
				update(posPf, -1);
			}
		}
		return ans;
	}
}

namespace full {
    map<int, long long> hashMap;
    vector<long long> cc;
    vector<int> pos[MAX];
    long long ans = 0;
    long long pf[MAX];
    long long b[MAX];
    int bit[MAX];

    void update(int id, int delta) {
		for (; id <= n; id += id & -id)
			bit[id] += delta;
	}

	int get(int id) {
		int res = 0;
		for (; id > 0; id -= id & -id)
			res += bit[id];
		return  res;
	}

	long long solve(void) {
        for (int i = 0; i <= n; ++i) {
            long long &value = hashMap[a[i]];
            if (value == 0) {
                value = Rand(1, 1e18);
            }
            b[i] = value;
        }
        long long XOR = b[0]; cc.push_back(XOR);
        for (int i = 1; i <= n; ++i) {
            XOR ^= b[i];
            cc.push_back(XOR);
            pf[i] = pf[i - 1] + a[i];
        }
        sort(cc.begin(), cc.end()); cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
        XOR = b[0];
        pos[lower_bound(cc.begin(), cc.end(), XOR) - cc.begin()].push_back(0);
        for (int i = 1; i <= n; ++i) {
            XOR ^= b[i];
            pos[lower_bound(cc.begin(), cc.end(), XOR) - cc.begin()].push_back(i);
        }
        #define ID(value) (lower_bound(v.begin(), v.end(), value) - v.begin() + 1)
        for (int i = 0; i <= n; ++i) if (pos[i].size() > 1) {
            vector<long long> v;			  for (int id: pos[i]) v.push_back(pf[id]);
			sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
			for (int id: pos[i]) {
				int posPf = ID(pf[id]);
				ans += get(posPf - 1);
				update(posPf, +1);
			}
			for (int id: pos[i]) {
				int posPf = ID(pf[id]);
				update(posPf, -1);
			}
        }
        return ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r",  stdin);
		freopen(task".out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		tmp.push_back(a[i]);
	}
	sort(tmp.begin(), tmp.end());
	tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
	for (int i = 1; i <= n; ++i) id[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
	if (subtask3::ok()) cout << subtask3::solve(); else if (n <= 2000) cout << subtask2::solve(); else cout << full::solve();

	return 0;
}
