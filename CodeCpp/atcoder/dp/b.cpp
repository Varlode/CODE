#include<bits/stdc++.h>
using namespace std;

const int maxN = 100001;
int h[maxN], a[maxN];

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];
    fill(a, a + n, 1000000001);
    a[0] = 0;
    a[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++)
        for (int j = 1; j <= min(k, i); j++)
            a[i] = min(abs(h[i] - h[i - j]) + a[i - j], a[i]);
    cout << a[n - 1];
}
