#include<bits/stdc++.h>
using namespace std;

const int maxN = 2*1e5+5;
int a[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int  i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int cnt = 1, ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) cnt++;
        else {
            if (cnt == 1) {cout << -1; return 0;}
            ans += (cnt / 3) + (cnt - (cnt / 3) * 3 + 1) / 2;
            cnt = 1;
        }
    }
    cout << ans;
}
