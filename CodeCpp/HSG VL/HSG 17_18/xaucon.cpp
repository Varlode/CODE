#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+9;
int n, m, pref[2*maxN], ans[maxN], cnt = 0;
string s1, s2, s;

int main() {
    freopen("xaucon.inp", "r", stdin);
    freopen("xaucon.out", "w", stdout);
    cin >> s1 >> s2;
    n = s1.size(); m = s2.size();
    s = s2+'#'+s1;
    for (int i = 1; i < s.size(); i++) {
        int j = pref[i-1];
        while (j && s[i]!=s[j])
            j = pref[j-1];
        if (s[i] == s[j])
            j++;
        pref[i] = j;
        if (pref[i] >= m) ans[cnt++] = i-m-m+1;
    }
    // for (int i = 0; i < s.size(); i++) cout << pref[i] << ' '; cout << endl;
    for (int i = 0; i < cnt-1; i++) cout << ans[i] << ' '; cout << ans[cnt-1];
}