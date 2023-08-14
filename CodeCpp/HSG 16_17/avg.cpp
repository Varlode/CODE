#include<bits/stdc++.h>
using namespace std;

const int maxN = 1009;
int m, n, a[maxN], ans = 0;

int main() {
    freopen("avg.inp", "r", stdin);
    freopen("avg.out", "w", stdout);
    cin >> m;
    while (m--) {
        cin >> n;
        ans = 0;
        map<int, int> l;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                ans += l[2*a[i]-a[j]];
            }
            l[a[i]]++;
        }
        cout << ans << endl;
    }
}