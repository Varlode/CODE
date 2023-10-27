#include<bits/stdc++.h>
using namespace std;

const int maxN = 100001;
int a[maxN], b[maxN], c[maxN];

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i] = max(b[i - 1], c[i - 1]) + a[i];
        b[i] = max(a[i - 1], c[i - 1]) + b[i];
        c[i] = max(b[i - 1], a[i - 1]) + c[i];
    }
    cout << max(max(a[n - 1], b[n - 1]), c[n - 1]);
}
