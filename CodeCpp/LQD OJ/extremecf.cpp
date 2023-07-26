#include<bits/stdc++.h>
using namespace std;

int sieutron(int n) {
    int muoi = 10, cnt = 1;
    while (n > muoi) {
        cnt++;
        muoi *= 10;
    }
    int ans = (cnt - 1) * 9 + (n / (muoi / 10));
    return ans;
}

void solve() {
    int n; cin >> n;
    int x; for (int i = 0; i < n; i++) {
        cin >> x;
        cout << sieutron(x) << "\n";
    }
}

int main(){
    //int t; cin >> t;
    //while (t--)
        solve();
}
