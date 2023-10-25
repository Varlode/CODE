#include<bits/stdc++.h>
using namespace std;

int ans, n, cnt;
string s;

bool check() {
    int size = s.size()-1;
    for (int i = 1; i <= (size+1)/2; i++) {
        string s1, s2;
        for (int j = size; j > size-i; j--) s1.push_back(s[j]);
        for (int j = size-i; j > size-2*i; j--) s2.push_back(s[j]);
        if (s1 == s2) return false;
    }
    return true;
}

void tudep(int u) {
    if ((n-s.size())/4 + cnt >= ans) return;
    for (int i = 'A'; i <= 'C'; i++) {
        s.push_back(i);
        if (check()) {
            cnt += (i == 'C');
            if (cnt + (n-s.size())/4 < ans) {
                if (s.size() == n)
                    ans = cnt;
                tudep(u+1);
            }
            cnt -= (i == 'C');
        }
        s.pop_back();
    }
    if (u+1 >= n) return;
}

int main() {
    cin >> n;
    ans = n;
    tudep(0);
    cout << ans;
}