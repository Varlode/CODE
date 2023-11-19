#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
char tmp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    string s; cin >> s;
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, k; cin >> l >> r >> k;
        l--; r--;
        k %= (r-l+1);
        int sz = r-l+1;
        for (int j = l; j <= r; j++) tmp[j] = tmp[j+sz] = s[j]; 
        for (int j = l; j <= r; j++) s[j] = tmp[r+j-l-k+1];
    }
    cout << s;
}