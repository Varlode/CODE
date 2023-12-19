/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2 << 21;
int n, L, R, sz;
int a[N];

long long calc(int s) {
    vector<int> mark(sz, 0);

    int cnt = 0;
    long long res = 0;

    int j = 1;
    for (int i = 1; i <= n; i++) {
        cnt += (mark[a[i]] == 0);
        mark[a[i]]++;
        while (j <= n && cnt > s) {
            mark[a[j]]--;
            cnt -= (mark[a[j]] == 0);
            j++;
        }
        res += i-j+1;
    }
    return res;
}

void solve() {
    cin >> n >> L >> R;

    vector<int> val(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[i-1] = a[i];
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    sz = val.size();

    for (int i = 1; i <= n; i++) a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();

    cout << calc(R) - calc(L-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
