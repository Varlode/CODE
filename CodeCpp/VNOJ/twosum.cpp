#include<bits/stdc++.h>
using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x; cin >> n;

    int a[n + 1];
    a[-1] = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = a[i - 1] + x;
    }

    int k = -1, res = 0 ;
    while (k < n - 2) {
        int i = k + 1, j = k + 2;
        while(i < n && j < n) {
            while (a[i] - a[k] < a[j] - a[i] && i < j) i++; 
            while (a[i] - a[k] > a[j] - a[i] && j < n) j++; 
            if (a[i] - a[k] == a[j] - a[i]) {
                res = max(res, j - k);
                j++;
            }
        }
        k++;
    }
    cout << res;

}