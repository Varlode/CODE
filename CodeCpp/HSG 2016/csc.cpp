#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
int a[maxN], n, m = 0, d = 0, max_pos = -1e9;

int main() {
    // freopen("csc.inp", "r", stdin);
    // freopen("csc.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= 100; i++) {
        map<int, int> mp;
        int tmp = 0, tmp_pos = -1e9;
        for (int j = 1; j <= n; j++) {
            mp[a[j]] = max(mp[a[j]-i]+1, mp[a[j]]);
            if (mp[a[j]] >= tmp) {
                tmp = mp[a[j]];
                tmp_pos = j;
            }
        }
        if (tmp >= m) {
            m = tmp;
            d = i;
            max_pos = tmp_pos;
        }
    }
    cout << m << ' ' << d << endl;
    for (int i = a[max_pos]-(m-1)*d; i <= a[max_pos]; i += d) {
        cout << i << endl;
    }
}