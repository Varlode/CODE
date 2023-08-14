#include<bits/stdc++.h>
using namespace std;

int n, q, t, x, tmp;
vector<int> a;

int main() {
    freopen("kehoach.inp", "r", stdin);
    freopen("kehoach.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> t;
        tmp = upper_bound(a.begin(), a.end(), t) - a.begin();
        cout << tmp << endl;
    }
}