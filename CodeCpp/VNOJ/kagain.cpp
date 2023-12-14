/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 4e4;
int n, a[N], l[N], r[N];

void reset() {
    a[0] = a[n+1] = 0;
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    reset();
    vector<int> s;
    s.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (s.size() && a[s.back()] >= a[i]) s.pop_back();
        l[i] =s.back();
        s.push_back(i);
    }
    s.clear();
    s.push_back(n+1);
    for (int i = n; i >= 1; i--) {
        while (s.size() && a[s.back()] >= a[i]) s.pop_back();
        r[i] = s.back();
        s.push_back(i);
    }

    int mx = 0, ans_l = 0, ans_r = 0;
    for (int i = 1; i <= n; i++) {
        if (mx < a[i]*(r[i]-l[i]-1)) {
            mx = a[i]*(r[i]-l[i]-1);
            ans_l = l[i]+1;
            ans_r = r[i]-1;
        }
        else if (mx == a[i]*(r[i]-l[i]-1)) {
            if (ans_l > l[i]+1) {
                ans_l = l[i]+1;
                ans_r = r[i]-1;
            }
        }
    }
    cout << mx << ' ' << ans_l << ' ' << ans_r << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
