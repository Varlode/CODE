#include<bits/stdc++.h>
using namespace std;

const int maxN = 10005;
int a[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cout << a[n - k];
}
