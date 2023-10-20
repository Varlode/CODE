#include<bits/stdc++.h>
using namespace std;

pair<int, int> a[100009];
int n;
int main() {
    freopen("doanhthu.inp", "r", stdin);
    freopen("doanhthu.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = make_pair(x, i);
    }
    sort(a+1, a+n+1);
    cout << a[n].first << endl;
    int i = n;
    while (a[n].first == a[i].first) i--;
    cout << n - i << endl;
    i++;
    for (; i < n; i++) cout << a[i].second << ' '; cout << a[n].second;
}