/* VOI
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    dung chia can de lam
    moi block la mot cay BIT hoac segment Tree luu gia tri
    de tim so luong gia tri lon k co trong block

    luc tinh tong cac block co the dung tiep BIT
    => thuat chuan se dung BIT2D + chia can

    luu y: segment tree TLE

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

const int N = 3e4+1;
const int LIM = 1e4+10;
const int BL_SZ = 200;
int n, q, a[N];

struct BIT {
    int bt[LIM];

    void upd(int i, int v) {
        for (; i < LIM; i += i&(-i)) bt[i] += v;
    }

    int get(int i) {
        int res = 0;
        for (; i > 0; i -= i&(-i)) res += bt[i];
        return res;
    }
} v[BL_SZ];

int get(int l, int r, int k) {
    int res = 0;
    int blockL = (l+BL_SZ-1)/BL_SZ;
    int blockR = r/BL_SZ;
    if (blockR <= blockL) {
        for (int i = l; i <= r; i++) res += (a[i] > k);
    }
    else {
        for (int i = blockL; i < blockR; i++)
            res += BL_SZ-v[i].get(k);
        for (int i = l, lim = blockL*BL_SZ; i < lim; i++)
            res += (a[i] > k);
        for (int i = blockR*BL_SZ; i <= r; i++)
            res += (a[i] > k);
    }
    return res;
}

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[i/BL_SZ].upd(a[i], 1);
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type, x, y, z;
        cin >> type >> x >> y;
        if (type == 0) {
            int block = x/BL_SZ;
            v[block].upd(a[x], -1);
            v[block].upd(y, 1);
            a[x] = y;
        }
        else {
            cin >> z;
            cout << get(x, y, z) << '\n';
        }
    }
}

int main(void) {
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
