#include <bits/stdc++.h>
using namespace std;

int n, mark[27];
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> s;
    long double mn = 1.1;
    int ans_l = 0, ans_r = 0;
    for (int doRucRo = 1; doRucRo <= 26; doRucRo++) {
        for (int i = 0; i <= 26; i++) mark[i] = 0;

        int l = 0, r = 0, cnt = 0, mx_len = 0, 
            tmp_r = 0, tmp_l = 0;

        while (r < n) {
            cnt += (mark[s[r]-'a'] == 0);
            mark[s[r]-'a']++;
            while (cnt > doRucRo) {
                cnt -= (mark[s[l]-'a'] == 1);
                mark[s[l]-'a']--;
                l++;
            }
            if (cnt <= doRucRo && mx_len < r-l+1) {
                mx_len = r-l+1;
                tmp_r = r+1;
                tmp_l = l+1;
            }
            r++;
        }
        if (mn > (long double) doRucRo/mx_len) {
            mn = (long double) doRucRo/mx_len;
            ans_l = tmp_l;
            ans_r = tmp_r;
        }
    }
    cout << ans_l << ' ' << ans_r;
}  