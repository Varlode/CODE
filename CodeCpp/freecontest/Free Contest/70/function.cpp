/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

/* NHAP -----------------------

    f(n) = -1 + 2 + -3 + 4 + ... + (-1)^n*n
    s(n) =  1 + 2 +  3 + 4 + ... + n
    f(n)+s(n) = 2*(2 + 4 + ... + n (if n even else 0))
    f(n)+s(n) = 4*(1 + 2 + ... + n/2) = 2*s(n/2)
    f(n) = 4*s(n/2)-s(n);

*///---------------------------

#include <bits/stdc++.h>
using namespace std;

inline long long s(long long n) {
    if (n&1) return (n+1)/2*n;
    return n/2*(n+1);
}

void solve(void) {
    long long n; cin >> n;
    cout << 4ll*s(n/2) - s(n);
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
