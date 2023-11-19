#include <bits/stdc++.h>
using namespace std;

#define ll long long

int bNeed, sNeed, cNeed;
int bHad, sHad, cHad;
int bShop, sShop, cShop;
ll money;

bool check(ll m) {
    ll b = max(0ll, (bNeed*m*1ll - bHad)*bShop*1ll);
    ll s = max(0ll, (sNeed*m*1ll - sHad)*sShop*1ll);
    ll c = max(0ll, (cNeed*m*1ll - cHad)*cShop*1ll);
    // cout << m << ' ' << b << ' ' << s << ' ' << c << '\n';
    // cout << ((b+s+c) <= money) << '\n';
    return (b+s+c) <= money;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    string s; getline(cin, s);
    for (char c: s) {
        if (c == 'B') bNeed++;
        if (c == 'S') sNeed++;
        if (c == 'C') cNeed++;
    }
    cin >> bHad >> sHad >> cHad;
    cin >> bShop >> sShop >> cShop;
    cin >> money;
    ll l = 0, r = money+bHad*bShop+sHad*sShop+cHad*cShop, ans = 0;
    while (l <= r) {
        ll m = l + (r-l)/2;
        if (check(m)) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    cout << ans;
}