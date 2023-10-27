#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a[i];
    } 
    sort(a, a+n-1);
    for (int i = 0; i < n; i++) {
        if (i+1 != a[i]) {
            cout << i+1 << endl;
            break;
        }
    }
}  