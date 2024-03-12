#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, a[N], ans;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int A = 1e9+1, B = 1e9+1;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= A && a[i] <= B) {
            A = a[i];
        }
        else if (a[i] > A && a[i] > B) {
            A = a[i];
            ans++;
        }
        else {
            B = a[i];
        }
        if (A > B) swap(A, B);
    }
    cout << ans;
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
