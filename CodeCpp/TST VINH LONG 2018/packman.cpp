#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+9;
int n, flag, ans = 0;
char s[maxN];

int check1(int d, int i) {
    int cnt = 0;
    while (s[i] != 'P' && i < n) {
        i++;
        cnt++;
    }
    if (cnt > d) return false;
    if (i == n) return false;
    i++;
    while (i < n && cnt+1 < d && s[i] != 'P') {
        i++;
        cnt += 2;
    }
    return i;
}

int check2(int d, int i) {
    int cnt = 0;
    while (s[i] != 'P' && i < n) {
        i++;
        cnt += 2;
    }
    if (cnt > d) return false;
    if (i == n) return false;
    i++;
    while (i < n && cnt < d && s[i] != 'P') {
        i++;
        cnt++;
    }
    return i;
}

bool check(int d) {
    int i = 0;
    // cout << endl << d << endl;
    while (i < n) {
        int cnt = 0;
        // cout << i << ' ' << s[i] << ' ';
        if (s[i] == 'P') {
            i++;
            while (i < n && cnt < d && s[i] != 'P') {
                i++;
                cnt++;
            }
        } else {
            if (s[i] == '.') {
                i++;
                continue;
            }
            i = max(check1(d, i), check2(d, i));
            if (i == 0) return false;
        }
    }
    return true;
}

int main() {
    freopen("packman.inp", "r", stdin);
    freopen("packman.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    int l = 1, r = 2*n;
    while (l <= r) {
        int m = l+(r-l)/2;
        if (check(m)) {
            ans = m;
            r = m-1;
        } else
            l = m+1;
    }
    cout << ans;
}