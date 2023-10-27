#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n < 4) {
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }  
}