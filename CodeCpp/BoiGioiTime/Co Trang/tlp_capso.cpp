#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int a[N], b[N];
int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b, b+m, -a[i])-b-1;
        if (j == -1) j = 0;
        ans = min(ans, abs(a[i] + b[j]));
    }
    
    cout << ans << endl;
}

/* NHAP
5 5
-84 -71 -64 -22 34
-66 16 19 37 79
    ans = 0
*/