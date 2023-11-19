#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        int a; string ans = "no\n";
        while (x--) {
            cin >> a;
            if (a == y)
                ans = "yes\n";
        }
        cout << ans;
    }
}