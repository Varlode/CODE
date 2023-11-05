#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[3030];

void check();

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;   
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int l, r, x; cin >> l >> r >> x;
        for (int j = l; j <= r; j++) a[j] += x;
        
    }
}