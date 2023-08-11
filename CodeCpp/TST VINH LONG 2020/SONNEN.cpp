#include<bits/stdc++.h>
using namespace std;

int n;
string s1, s2, sn;

string op(string a, string b) {
    int mem = 0;
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    string ans = a;
    int i = a.size() - 1;
    while (i >= 0) {
        ans[i] = char((a[i]+b[i]-2*'0'+mem)%10+'0');
        mem = (a[i]+b[i]-2*'0'+mem)/10;
        i--;
    }
    if (mem == 1) ans = '1' + ans;
    return ans;
}

int main() {
    freopen("sonnen.inp", "r", stdin);
    freopen("sonnen.out", "w", stdout);
    cin >> n;
    s1 = s2 = '1';
    sn = '\0';
    if (n <= 2) {
        cout << 1;
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        sn = op(s1, s2);
        s1 = s2;
        s2 = sn;
    }
    cout << sn;
}