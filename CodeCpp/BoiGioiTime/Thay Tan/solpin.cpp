#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, q, p, u, v, x;
int a[N], pref[N], pos = 0;

int get_sum(int a, int b) {
    return pref[b] - pref[a-1];
}

int query(int a, int b) {
    a += pos; b += pos;
    if (a > n) a -= n;
    if (b > n) b -= n;
    // cout << a << ' ' << b << endl;
    if (a <= b) return get_sum(a, b);
    else return (get_sum(1, b) + get_sum(a, n));    
}

void update(int a) {
    pos += a;
    if (pos > n) pos -= n;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = a[i]+pref[i-1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> p;
        if (p) {
            cin >> u >> v;
            cout << query(u, v) << endl;
        } else {
            cin >> x;
            update(x);
        }
    }
}