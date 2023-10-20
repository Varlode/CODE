#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i*i <= n+i; i++) {
        for (int j = 1; j*i < n; j++) {
            cout << i << " x " << j << " + " << n-i*j << " = " << n << endl;
            if (i!=j) ans++;
            ans++;
        }
    }
    cout << ans;
}