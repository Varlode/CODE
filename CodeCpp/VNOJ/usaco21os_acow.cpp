#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n, k, l;
    cin >> n >> k >> l;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++) 
        cin >> a[i];

    sort(a.begin(), a.end(), greater<long long>());

    long long hi = n, lo = 0;

    while (lo < hi) {
        
        long long mi = lo + (hi - lo + 1) / 2;
        long long i = mi - 1;

        if (a[i] + k < mi) {
            hi = mi - 1;
            continue;
        }

        long long s = k * l;
        bool ok = false;

        while (s >= (mi - a[i]) && i >= 0) {
            s -= (mi - a[i]);
            if (i == 0) ok = true;
            i--;
        }

        if (!ok) 
            hi = mi - 1;
        else
            lo = mi;
    }
    cout << lo;
}