#include<bits/stdc++.h>
using namespace std;

int a, b, c;
int ans;
vector<int> ans_vec;

int digits(long long s) {
    int ans = 0;
    while (s > 0) {
        ans += s%10;
        s /= 10;
    }
    return ans;
}

int main () {
    cin >> a >> b >> c;
    for (int i = 0; i <= 81; i++) {
        long long x = b*pow(i, a) + c;
        if (x <= 0) continue;
        if (x >= 1e9) break;
        if (digits(x) == i) {
            ans++;
            ans_vec.push_back(x);
        }
    }
    if (ans) {
        cout << ans << endl;
        for (int i: ans_vec) cout << i << ' ';
    } else cout << 0;
}