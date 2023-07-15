#include<bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    if (0 >= q || q >= 10000) {cout << "N"; return 0;}
    
    q = q*100;
    if (1000 < q && q <= 2000) q -= q / 10;
    else if (2000 < q) q -= q * 15 / 100;
    
    cout << q;
}