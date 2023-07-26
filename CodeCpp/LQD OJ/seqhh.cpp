#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    unordered_map<int, long long> um;
    int x, tmp = 0; long long ans = 0;
    um[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        tmp += x;
        ans += um[tmp - k];
        um[tmp]++;
    }
    cout << ans;
}

int main(){
    //int t; cin >> t;
    //while (t--)
        solve();
}
