#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N], r[N], l[N], cnt = 0;
unordered_map<int, int> ml, mr;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cnt += ml[a[i]];
        l[i] = ml[a[i]];
        ml[a[i]]++;
    }
    for (int i = n; i >= 1; i--) {
        r[i] = mr[a[i]];
        mr[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt - l[i] - r[i] << endl;
    }
}