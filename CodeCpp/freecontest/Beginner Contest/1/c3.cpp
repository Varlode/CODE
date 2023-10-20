#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N];
unordered_map<int, int> mp;

int main() {
    int ans = 0;
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans += mp[k-x*x];
        mp[x]++;
    }
    cout << ans;
}