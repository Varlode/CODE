#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
long long n, K;

void solve() {
    cin >> n >> K;
    if (n <= K) cout << "Rua Win\n";
    else {
        if (n % (K+1) == 0) cout << "Tho Win\n";
        else cout << "Rua Win\n";
    }
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
