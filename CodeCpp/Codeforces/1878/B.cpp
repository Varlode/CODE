#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1, cnt = 0; cnt < n; i += 3, cnt++) 
            cout << i << ' ';
        cout << endl;
    }
}