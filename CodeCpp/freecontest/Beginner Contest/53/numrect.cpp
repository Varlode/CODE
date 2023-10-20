#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        n++, m++;
        cout << (int64_t) (n*(n-1)/2)*(m*(m-1)/2) << endl;
    }
}