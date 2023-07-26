#include<bits/stdc++.h>
using namespace std;

int N, S, a[1009], cnt, ans = 1e9+9;

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) 
        cin >> a[i];
    int l = 1, r = 1, s = 0;
    while (r <= N) {
        s += a[r];
        if (s >= S) {
            while (s >= S) {
                ans = min(ans, r - l + 1);
                s -= a[l];
                l++;
            }
        } else if (s < 0) {
            s = 0;
            l = r + 1;
        }
        r++;
    }
    (ans != 1e9+9)? cout << ans : cout << -1;
}