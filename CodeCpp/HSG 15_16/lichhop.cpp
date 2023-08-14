#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+9;
pair<int, int> a[maxN];
int n, d, c, f, ans;

int main() {
    freopen("lichhop.inp", "r", stdin);
    freopen("lichhop.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d >> c;
        a[i] = make_pair(c, d);
    }
    sort(a, a+n);
    f = ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second >= f) {
            f = a[i].first;
            ans++;
        }
    }
    cout << ans;
}