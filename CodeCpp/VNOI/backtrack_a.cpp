#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n][n];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j : a[i]) 
            cout << j;
}