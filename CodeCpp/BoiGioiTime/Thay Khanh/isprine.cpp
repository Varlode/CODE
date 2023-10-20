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

int check(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

main() {
    int n; cin >> n;
    while (n > 2) {
        auto timer1 = clock();
        while (n--) {
            if (check(n)) {
                cout << n << endl;
                break;
            }
        }
        auto timer2 = clock();
        cout << (double)(timer2-timer1)/CLOCKS_PER_SEC << endl;
        n--;
    }
}  