#include <bits/stdc++.h>
using namespace std;

const int N =  10001000;
int n, x;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = n; long long ans = 0;
    while (l <= r) {
        if (a[r]+a[l] > x) r--;
        else {
            ans += (r-l);
            l++;
        }
    }
    cout << ans;
}