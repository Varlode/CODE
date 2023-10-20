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

const int N = 1e6;
int n, q, c;
vector<int> a;

main() {
    freopen("kehoach.inp", "r", stdin);
    freopen("kehoach.out", "w", stdout);
    cin >> n;
    // a.push_back(-1);
    REP(i, n) {
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(), a.end());
    cin >> q;
    REP(i, q) {
        cin >> c;
        cout << upper_bound(a.begin(), a.end(), c) - a.begin() << endl;
    }
}  