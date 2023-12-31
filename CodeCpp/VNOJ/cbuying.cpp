/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    quy bai toan ve nhieu loai keo va moi loai co gia Pi va Ci cai
    hoi lam sao de chon nhieu cai keo nhat

    => sort lai theo Pi, vi moi vien co gia Pi

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5+1;
ll n, B;
pair<ll, ll> a[N];

void solve(void) {
    cin >> n >> B;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a+1, a+1+n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].second <= B / a[i].first) {
            B -= a[i].first * a[i].second;
            ans += a[i].second;
        }
        else {
            ans += B / a[i].first;
            break;
        }
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
//        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
