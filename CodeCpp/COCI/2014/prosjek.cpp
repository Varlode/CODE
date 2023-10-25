#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int ans[N], n;

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ans[i] = a*i-sum;
        sum += ans[i];
    }
    cout << ans[1];
    for (int i = 2; i <= n; i++) cout << ' ' << ans[i];
}