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
int a[N], pref[N];
unordered_map<int, int> m;

main() {
    int n, s; cin >> n >> s;
    string ans = "NO";
    FOR(i, 1, n) cin >> a[i];
    m[0] = 1;
    FOR(i, 1, n) {
        pref[i] = pref[i-1]+a[i];
        if (m[pref[i]-s]) ans = "YES";
        m[pref[i]]++;
    }
    cout << ans << endl;

}  