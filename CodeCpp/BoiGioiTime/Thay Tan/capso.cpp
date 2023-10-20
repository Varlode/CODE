#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second

const int N= 1e6+100;
int a[N];

main() {
    // freopen("capso.inp", "r", stdin);
    // freopen("capso.out", "w", stdout);
    int n; cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int i = 1;
    while (i <= n && a[i] < 0) i++;

    int l = i - 1, r = i, ans = 0;
    while (r <= n) {    
        while (l >= 1 && a[l] > -a[r]) l--;
        if (a[l]+a[r] == 0) ans++;
        r++;
    }

    cout << ans;
}  