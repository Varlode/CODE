#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+9;
int n, a[maxN];

int main() {
    freopen("thongke.inp", "r", stdin);
    freopen("thongke.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int cnt = 1, max_cnt = 1, diff = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            diff++;
            cnt = 1;
        } else {
            cnt++;
            max_cnt = max(max_cnt, cnt);
        }
    }
    cout << diff << endl << max_cnt;
}