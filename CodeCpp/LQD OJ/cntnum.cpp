#include<bits/stdc++.h>
using namespace std;

void solve1() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < 0) cnt1++;
        if (x > 0) cnt2++;
    }
    cout << cnt1 << " " << cnt2;
}

void solve() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    float a, b, c; cin >> a >> b >> c;
    float ma = max(a, max(b, c)), mi = min(a, min(b, c));
    cout << ((a != ma && a != mi) ? a : ((b != ma && b != mi)? b : c));
}

int main(){
    //int t; cin >> t;
    //while (t--)
        solve();
}
