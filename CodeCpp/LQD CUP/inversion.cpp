/**
    ngbaro2k6 (Nguyen Gia Bao)
    Saturday 2023-10-21
**/

#include "bits/stdc++.h"

using namespace std;

const int N = 5e5+10;

int a[N];

struct node {
    int64_t inv = 0;
    int freq[40];

    void combine (const node& l, const node& r) {
        inv = l.inv + r.inv;
        for (int i = 39; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                // frequency of bigger numbers in the left * frequency of smaller numbers on the right
                inv += 1LL * l.freq [i] * r.freq [j];
            }
            freq [i] = l.freq [i] + r.freq [i];
        }
    }
} tree[4*N];

void build (int v, int tl, int tr) {
    if (tl == tr) {
        tree [v].inv = 0;
        tree [v].freq [a [tl]] = 1;
    }
    else {
        int tm = (tl + tr) / 2;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        tree [v].combine(tree [2 * v + 1], tree [2 * v + 2]);
    }
}

node inv_cnt (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return node();
    if (tl == l && tr == r)
        return tree [v];
    int tm = (tl + tr) / 2;
    node result;
    result.combine(inv_cnt(2 * v + 1, tl, tm, l, min(r, tm)), inv_cnt(2 * v + 2, tm + 1, tr, max(l, tm + 1), r));
    return result;
}

void solve () {
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        c -= 'a';
        a[i] = c;
    }
    
    build(0, 0, n - 1);

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        node result = inv_cnt(0, 0, n - 1, x, y);
        cout << result.inv << '\n';
    }
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(10);
    std::cout << std::fixed << std::boolalpha;

    int t = 1;
//  std::cin >> t;
    while (t--)
        solve();

    return 0;
}