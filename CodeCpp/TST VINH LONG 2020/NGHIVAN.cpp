#include<bits/stdc++.h>
using namespace std;

int o1, o2, o3, o4, n, cnt[4], s, b, d;

int check(int f) {
    if (0 <= f && f <= 10) return 1;
    if (10 < f && f < 100) return 2;
    if (100 <= f && f <= 255) return 3;
}

int main() {
    freopen("nghivan.inp", "r", stdin);
    freopen("nghivan.out", "w", stdout);
    cin >> n;
    s = b = d = 0;
    while (n--) {
        cnt[1] = 0, cnt[2] = 0, cnt[3] = 0;
        cin >> o1 >> o2 >> o3 >> o4;
        cnt[check(o1)]++; cnt[check(o2)]++; cnt[check(o3)]++; cnt[check(o4)]++;
        if (cnt[3] >= 2 || cnt[1] == 4) continue;
        if (cnt[3] == 1 && cnt[1] == 3) continue;
        if (cnt[3]+cnt[2] >= 2) d++;
        else b++;
        s++;
    }
    cout << s << ' ' << b << ' ' << d;
}