#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second

const int N = 110;
int n, m;
int a[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    int ans = 0, cnt = 0;
    FOR(i, 1, m) FOR(j, 1, n) {
        char c; cin >> c;
        if (c != '.')
            a[i][j] = 1;
    }

    FOR(i, 1, m) {
        cnt = 0;
        FOR(j, 1, n) {
            cnt += a[i][j];
            if (cnt&1) {
                ans++;
            }
        }
    }
    cout << ans;
}