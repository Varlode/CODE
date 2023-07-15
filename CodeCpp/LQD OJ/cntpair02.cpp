#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x, res; cin >> n >> k;
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        cin >> x;
        res += m[k - x];
        m[x]++;
    }
    cout << res;
}