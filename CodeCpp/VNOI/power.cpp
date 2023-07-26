#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    long long t, i = 0;; 
    cin >> t;

    while (i++ < t) {

        long long l, r;
        cin >> l >> r;

        for (int k = 40; k > 0; k--) {
            long x = 2;
            while (pow(x, k) <= r) x++;
            if (pow(x - 1, k) >= l) {
                cout << "Case #" << i << ": " << k << endl;
                break;
            }
        }
    }
}