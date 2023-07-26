#include<bits/stdc++.h>
using namespace std;

void solve() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    map<int, int> m;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (m[k - a[i]] != 0) {
            cout << m[k - a[i]] << " " << i + 1;
            ok = false;
            break;
        }
        m[a[i]] = i + 1;

    }
    if (ok) cout << "IMPOSSIBLE";
}

int main(){
    //int t; cin >> t;
    //while (t--)
        solve();
}
