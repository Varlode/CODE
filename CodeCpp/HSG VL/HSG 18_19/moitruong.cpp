#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("moitruong.inp", "r", stdin);
    freopen("moitruong.out", "w", stdout);
    int n, u, min_id = 1e9, max_id = 0; 
    cin >> n >> u;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a == 1) {
            min_id = min(min_id, i);
            max_id = max(max_id, i);
        }
    }
    cout << min(abs(max_id-u)+max_id-min_id, abs(min_id-u)+max_id-min_id); 
}