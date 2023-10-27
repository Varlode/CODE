#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, p, x;
long long ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;    
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x < p) ans += p-x;
        p = max(p, x);
    }
    cout << ans;
}  
