#include<bits/stdc++.h>
using namespace std;

const int maxN = 60001;
int t[maxN], r[maxN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n - 1; i++) cin >> r[i];
    for (int i = 1; i < n; i++)
        t[i] = min(t[i - 1] + t[i], t[i - 2] + r[i - 1]);
    cout << t[n - 1];
}
