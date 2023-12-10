/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int base = 31;
const ll MOD = 1e9+7;
const int N = 1e6+1;

ll POW[N], hashT[N];

void initHash(int sz) {
    POW[0] = 1;
    for (int i = 1; i <= sz; i++)
        POW[i] = POW[i-1] * base % MOD;
}

ll getHash(int l, int r) {
    return (hashT[r] - hashT[l - 1] * POW[r - l + 1] + MOD * MOD) % MOD;
}

void solve() {
    string t, p;
    cin >> t >> p;

    int szT = t.size(), szP = p.size();
    t = "~"+t;
    p = "~"+p;

    initHash(szT);

    ll hashP = 0;
    for (int i = 1; i <= szP; i++)
        hashP = (hashP * base + p[i] - 'a' + 1) % MOD;

    for (int i = 1; i <= szT; i++)
        hashT[i] = (hashT[i-1] * base + t[i] - 'a' + 1) % MOD;

    for (int i = 1; i+szP-1 <= szT; i++)
        if (hashP == getHash(i, i+szP-1))
            cout << i << ' ';
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
