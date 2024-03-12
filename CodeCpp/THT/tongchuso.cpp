#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
int n, a[N], X[N], b[N], sum;

void solve() {
    string s; cin >> s;
    n = (int) s.size();
    sum = 0;
    for (int i = 1; i <= n; i++) {
        X[i] = s[i-1] - '0';
        sum += X[i];
        a[i] = b[i] = 0;
    }

    int S1, S2, ok = 0;
    if (sum & 1) {
        S1 = S2 = (sum+9)/2;
        for (int i = 1; i < n; i++) {
            if (X[i] > 0 && X[i+1] < 9) {
                X[i] -= 1;
                X[i+1] += 10;
                a[i+1] = b[i+1] = X[i+1]/2;
                if (X[i+1] & 1) a[i+1]++;
                X[i+1] = 0;
                S1 -= a[i+1];
                S2 -= b[i+1];
                ok = i+1;
                break;
            }
        }
        if (ok == 0) {
            cout << -1 << '\n';
            return;
        }
    }
    else S1 = S2 = sum/2;

    for (int i = 1; i <= n; i++) {
        if (i == ok) continue;
        if (S1 - X[i] >= 0) {
            a[i] = X[i];
            S1 -= X[i];
            X[i] = 0;
        }
        else break;
    }
    for (int i = n; i >= 1; i--) {
        if (i == ok) continue;
        if (S2 - X[i] >= 0) {
            b[i] = X[i];
            S2 -= X[i];
            X[i] = 0;
        }
        else break;
    }
    for (int i = 1; i <= n; i++) if (X[i]) {
        a[i] = S1;
        b[i] = S2;
        X[i] = 0;
        break;
    }

    int i = 1; while (a[i] == 0 && i <= n) i++;
    for (; i <= n; i++) cout << a[i]; cout << ' ';
    i = 1; while (b[i] == 0 && i <= n) i++;
    for (; i <= n; i++) cout << b[i]; cout << '\n';
}

int main() {
    #define task "TASK"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--)
        solve();
}
