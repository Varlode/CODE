#include<bits/stdc++.h>
using namespace std;

const int maxN = 30005;

vector<int> a(maxN, 1000000001);

int main() {
    int n; cin >> n;
    a[0] = -1000000009;
    int tmp, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        int x = lower_bound(a.begin(), a.end(), tmp) - a.begin();
        a[x] = tmp;
        ans = max(ans, x);
    }
    cout << ans;
}
