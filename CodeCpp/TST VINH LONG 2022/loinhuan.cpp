#include<bits/stdc++.h>
using namespace std;

int n, l, ans, cnt[20000009];

int main() {
    cin >> n;
    while (n--) {
        cin >> l;
        ans += cnt[-l];
        cnt[l]++;
    }
    cout << ans << endl;
}