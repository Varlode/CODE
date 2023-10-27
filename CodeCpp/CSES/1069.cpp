#include<bits/stdc++.h>
using namespace std;

int n, ans, cnt = 1;
char p = 0;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s; n = s.size();
    for (int i = 0; i < n; i++) {
        cnt = (s[i]==p)? cnt+1: 1;
        p = s[i];
        ans = max(ans, cnt);
    }
    cout << ans;
}