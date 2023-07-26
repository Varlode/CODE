#include<bits/stdc++.h>
using namespace std;

void bai1() {
    int n;
    cin >> n;
    cout << abs(int(n / 100 - n % 100)) << " " << (int) n / 5 - 999 / 5 << " " << 99 - (n % 100) << "\n";
}

void bai2() {
    unsigned long long n, k;
    cin >> n >> k;

    int m; if (n % 2) m = 9; else m = 8;
    if (n <= m) {cout << 0 << "\n"; return;}
    long long  x = (n - m) / 2;
    cout << x << " " << x + m << " " << (int64_t) x*k + (x + m)*2*k << "\n";

}

void bai3() {
    long long n;
    cin >> n;
    long long TS0 = 1, inc = 1, tmp, cnt = 0, s = 0;
    while (s + TS0 + inc <= n) {
        s += TS0 + inc;
        TS0 += inc;
        inc += 2;
        cnt++;
    }
    cout << cnt << " \n";
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout << "bai1: " << endl;
    bai1(); bai1(); bai1(); bai1(); bai1();
    cout << "bai2: " << endl;
    bai2(); bai2(); bai2(); bai2(); bai2(); bai2();
    cout << "bai3: " << endl;
    bai3(); bai3(); bai3(); bai3();
}
