#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ldi pair<ld, int>
#define fi first 
#define se second 

#define pi 3.14159265359

const int N = 101010;
vector<ldi> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        ld d = sqrt(x*x + y*y);        
        ld angle = acos((ld) x / d);
        if (y < 0) angle = -angle;
        v.push_back({(ld) angle/pi * 180, i});
    }
    sort(v.begin(), v.end());
    ld mn = abs(180.0 - v.back().first + 180.0 + v.front().first);
    int ans_i = v.front().se, ans_j = v.back().se;
    for (int i = 1; i < (int) v.size(); i++) {
        if (v[i].fi - v[i-1].fi < mn) {
            mn = v[i].fi - v[i-1].fi;
            ans_i = v[i].se;
            ans_j = v[i-1].se;
        }
    }
    cout << ans_i << ' ' << ans_j;
} 