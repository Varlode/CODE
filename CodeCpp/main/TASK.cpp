/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
    cin >> s;
    n = s.size();
    s = '~' + s;
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += (s[i]-'0');
    sum %= 3;
    if (sum == 0) {
        while (s[i] == '9' && i <= n) i++;
        if (s[i] + 9 <= '9') s[i] += 9;
        if (s[i] + 6 <= '9') s[i] += 6;
        if (s[i] + 3 <= '9') s[i] += 3;
    }
    else if (sum == 1) {
        while (s[i] == '9' && i <= n) i++;

        if (s[i] + 8 <= '9') s[i] += 8;
        if (s[i] + 5 <= '9') s[i] += 5;
        if (s[i] + 2 <= '9') s[i] += 2;
    }
    else if (sum == 2) {
        while (s[i] == '9' && i <= n) i++;
        if (s[i] + 7 <= '9') s[i] += 7;
        if (s[i] + 4 <= '9') s[i] += 4;
        if (s[i] + 1 <= '9') s[i] += 1;
    }
    cout << s;
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
