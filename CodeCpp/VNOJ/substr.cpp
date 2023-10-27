#include<bits/stdc++.h>
using namespace std;

const int N = 1000100;
int pref[N], ans[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b; cin >> b >> a;
    string s = a+'#'+b;
    pref[0] = 1;
    int mem = 0, size = a.size();
    for (int i = 1; i <= s.size(); i++) {
        int j = pref[i-1];
        while (j && s[i] != s[j]) j = pref[j-1];
        if (s[i] == s[j]) j++;
        pref[i] = j;
        if (pref[i] > size) ans[mem++] = i-size+1;
    }
    for (int i = 0; i < mem-1; i++) cout << ans[i] << ' '; cout << ans[mem-1];
}
