#include<bits/stdc++.h>
using namespace std;

const int maxN = 2*1e5+5;
int a[maxN], b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        b[x] -= 1;
    }
    for (int i = 1; i < n; i++) cout << a[i] + k + b[i] << " ";
    cout << a[n] + k + b[n];
}
