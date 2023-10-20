#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int i = 0, j = 0;
    long long res = abs(a[0] + b[0]);
    
    while (i < n and j < n) {
        if (i + 1 == n) {
            while (j < n) {
                res = min(res, (long long) abs(a[i] + b[j]));
                j++;
            }
            break;
        }
        if (j + 1 == n) {
            while (i < n) {
                res = min(res, (long long) abs(a[i] + b[j]));
                i++;
            }
            break;
        }
        if (abs(a[i + 1] + b[j]) <= abs(a[i] + b[j + 1])) {
            res = min(res, (long long) abs(a[i + 1] + b[j]));
            i++;
        }
        else {
            res = min(res, (long long) abs(a[i] + b[j + 1]));
            j++;
        }
    }
    
    cout << res;
}