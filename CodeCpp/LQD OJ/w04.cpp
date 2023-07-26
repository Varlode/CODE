#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < 2*i - 1; j++)
            cout << j << " ";
        cout << 2*i - 1 << "\n";
    }
}
