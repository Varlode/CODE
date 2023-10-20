#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N], b[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n-1; i++) {
        cout << lower_bound(b, b+n, a[i]) - b << ' ';
    }
    cout << lower_bound(b, b+n, a[n-1]) - b;
}