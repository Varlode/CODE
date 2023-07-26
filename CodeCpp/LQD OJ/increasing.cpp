#include<bits/stdc++.h>
using namespace std;

bool a[1000005];

void solve() {
    int n; cin >> n;
    memset(a, false, sizeof(a));
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!a[x]) a[x] = true;
        else ok = false;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";

}

int main(){
    int t; cin >> t;
    while (t--) solve();
}

