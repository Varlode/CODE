#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6;
int n, m, pref[N];
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> s;
    n = (int) s.size();
    for (int i = 1; i < n; i++) if (s[i] == s[i-1]) pref[i-1] = 1;
    for (int i = 1; i < n; i++) pref[i] += pref[i-1];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        l-= 2; r -= 2;
        cout << pref[r] - pref[l] << endl;
    }
}