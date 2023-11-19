#include<bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int h; cin >> h;
        ans = max(h, ans);
    }
    cout << ans;
}