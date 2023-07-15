#include<bits/stdc++.h>
using namespace std;

const int maxN = 100001;
int h[maxN], a[maxN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    a[0] = 0;
    a[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++)
        a[i] = min(abs(h[i] - h[i - 1]) + a[i - 1], abs(h[i] - h[i - 2]) + a[i - 2]);
    cout << a[n - 1];
}
