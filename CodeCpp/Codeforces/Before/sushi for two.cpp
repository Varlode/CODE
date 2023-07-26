#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, res = 0, tmp = 0, t, eel = 0, tuna = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        
        
        cin >> t;
        
        if (t == 1) {
            if (tmp == 2) tuna = 0;
            tuna++;
        } else if (t == 2) {
            if (tmp == 1) eel = 0;
            eel++;
        }
        tmp = t;
        res = max(min(tuna, eel) * 2, res);
    }
    cout << res;
}