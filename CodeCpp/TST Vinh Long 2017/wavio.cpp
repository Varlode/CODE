#include<bits/stdc++.h>
using namespace std;

int n, l[1009], r[1009];
vector<int> a(1009);

int main() {
    freopen("wavio.inp", "r", stdin);
    freopen("wavio.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    l[1] = 1; r[n] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] >= a[j]) {
                l[i] = max(l[i], l[j]+1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (a[i] >= a[j]) {
                r[i] = max(r[i], r[j]+1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) 
        ans = max(l[i]+r[i+1], ans);
    cout << ans;
}