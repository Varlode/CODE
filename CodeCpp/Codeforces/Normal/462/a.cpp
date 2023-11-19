#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, a[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        char c; cin >> c;
        a[i][j] = c == 'o';
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (a[i][j-1] + a[i-1][j] + a[i+1][j] + a[i][j+1] & 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}