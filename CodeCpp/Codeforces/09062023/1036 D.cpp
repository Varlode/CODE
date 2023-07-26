#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long long s1 = 0, s2 = 0, s = 0;
    int n; cin >> n; int a[n];
    for (int i = 0; i < n; i++) {cin >> a[i]; s += a[i];}
    int m; cin >> m; int b[m];
    for (int i = 0; i < m; i++) {cin >> b[i], s -= b[i];}

    if (s != 0) {
        cout << -1;
        return 0;
    }

    int i = 0, j = 0, res = 0;

    while (i < n && j < m) {
        res++;
        s1 = a[i++];
        s2 = b[j++];
        while (s1 != s2) {
            if (s1 < s2) 
                s1 += a[i++];
            else
                s2 += b[j++];
        }
    }
    cout << res;
}