#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N];
unordered_map<int, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a, a+n);
    if (a[0] != a[n-1])
        cout << abs(a[0] - a[n-1]) << ' ' << 1LL * m[a[0]] * m[a[n-1]];
    else 
        cout << 0 << ' ' << 1LL*n*(n-1)/2;
}