#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;

    return true;
}

int main() {
    int n; cin >> n;
    if (n <= 0) {cout << "N"; return 0;}

    int s = 0, tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (isPrime(tmp)) s += tmp;
    }

    cout << s;

}