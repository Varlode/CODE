#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+9;
int n, L, bigM, maxB = 0, maxA = 0;
int a[maxN], b[maxN];

bool check(int m) {
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= m) continue;
        tmp += (m-a[i])/b[i] + ((m-a[i])%b[i]!=0);
    }
    return tmp <= L;
}

void bs(int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            bigM = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
}

int main() {
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        maxB = max(maxB, b[i]);
        maxA = max(maxA, a[i]);
    }
    bs(1, L*(maxB)+maxA);
    cout << bigM << endl;
}