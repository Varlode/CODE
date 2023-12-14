#include <bits/stdc++.h>
using namespace std;
#define task "pseqp"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 100010;
int n, q;
int b[MAX];
int posA[MAX];
int st[MAX << 2];

void update(int pos, int delta) {
    int id = 1, l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (pos <= mid) id <<= 1, r = mid;
        else id = id << 1 | 1, l = mid + 1;
    }
    st[id] += delta;
    while (id > 1) {
        id >>= 1;
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n >> q;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        posA[x] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        int dist = (i - posA[b[i]] + n) % n; update(dist, +1);
    }
    while (q--) {
        int i, j, dist; cin >> i >> j; --i; --j;
        dist = (i - posA[b[i]] + n) % n; update(dist, -1);
        dist = (j - posA[b[j]] + n) % n; update(dist, -1);
        swap(b[i], b[j]);
        dist = (i - posA[b[i]] + n) % n; update(dist, +1);
        dist = (j - posA[b[j]] + n) % n; update(dist, +1);
        cout << st[1] << '\n';
    }
	return 0;
}
