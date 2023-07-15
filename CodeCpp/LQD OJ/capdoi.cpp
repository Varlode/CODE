#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    unordered_map<int, long long> um;
    int x; long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x*2 > k) continue;
        ans += um[k - x];
        um[x]++;
    }
    cout << ans;
}

int main(){
    //int t; cin >> t;
    //while (t--)
        solve();
}
