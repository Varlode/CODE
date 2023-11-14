#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, pref0[N], pref1[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        pref0[i] += pref0[i-1] + (a==0);
        pref1[i] += pref1[i-1] + (a==1);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) {
        mx = max(mx, pref1[n]-pref1[j]+pref0[j]-pref0[i-1]+pref1[i-1]);
    }
    cout << mx;
}