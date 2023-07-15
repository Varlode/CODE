#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int tmp = 0, x;
        for (int i = 0; i < 3; i++) {
            cin >> x;
            tmp += x;
        }
        if (tmp >= 2) ans++;
    }
    cout << ans;
}

