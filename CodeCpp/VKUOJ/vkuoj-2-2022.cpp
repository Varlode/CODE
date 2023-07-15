#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    if (k == 1) {
        cout << (int) sqrt(n) - 1;
        return 0;
    }
    if (k == 2) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) cnt += (int) sqrt(n / i), cout << i;
        }
        cout << cnt;
        return 0;
    }
    if (k == 3) {


    }
}