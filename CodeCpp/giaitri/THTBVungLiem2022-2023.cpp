// stream den khi dien thoai sac day pin
#include<bits/stdc++.h>
using namespace std;

void bai1() {
    int n; cin >> n;
    int m = n, tmp1 = 0, tmp2 = 1; while (m > 0) {
        tmp1 += m % 10;
        tmp2 *= m % 10;
        m /= 10;
    }
    cout << tmp1 << " " << tmp2 << " ";
    int i;
    for (i = 9; i >= 1; i--) if (n * i < 1000) break;
    cout << n * i;
}

void bai2() {
    unsigned long long n;
    cin >> n;
    unsigned long long tong = 1, tmp = 1, cnt = 1;
    while (tong < n) {
        tmp += cnt;
        tong += tmp;
        cnt++;
    }
    cout << cnt;
}

int main() {
    bai2();
}

