#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n <= 0) {cout << "N"; return 0;}
    
    cout << (n / 4 * (n / 4 + 1)) / 2 * 4 - ((n / 20 * (n / 20 + 1)) / 2) * 20;
}