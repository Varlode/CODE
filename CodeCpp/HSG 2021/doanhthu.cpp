#include<bits/stdc++.h>
using namespace std;

int N, S, a[1009], cnt, ans = 1e9+9;

int main() {
    
    freopen("doanhthu.inp", "r", stdin);
    freopen("doanhthu.out", "w", stdout);
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i-1];
        for (int j = 0; j < i; j++) 
            if (a[i] - a[j] >= S) {
                ans = min(ans, i-j);
            }
    }
    (ans != 1e9+9)? cout << ans : cout << -1;
}