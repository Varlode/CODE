#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
int a[maxN], n, m = 0, d = 0, min_pos = -1e9;

int main() {
    freopen("csc.inp", "r", stdin);
    freopen("csc.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= 100; i++) {
        map<int, int> mp, pos;
        int tmp = 0, tmp_pos = -1e9;
        for (int j = 1; j <= n; j++) {
            if (pos[a[j]-i] != 0) pos[a[j]] = pos[a[j]-i];
            else pos[a[j]] = j;
            mp[a[j]] = mp[a[j]-i]+1;
            if (mp[a[j]] >= tmp) {
                tmp = mp[a[j]];
                tmp_pos = pos[a[j]];
            }
        }
        if (tmp > m) {
            m = tmp;
            d = i;
            min_pos = tmp_pos;
        }
        if (tmp == m) {
            min_pos = max(min_pos, tmp_pos);
        }
    }
    cout << m << ' ' << d << endl;
    for (int i = a[min_pos]; i <= a[min_pos]+(m-1)*d; i += d) {
        cout << i << endl;
    }
}