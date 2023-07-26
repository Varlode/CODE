#include<bits/stdc++.h>
using namespace std;

int l[200009], cnt_l[200009], r[200009], cnt_r[200009];

void solve()
{
    string s; cin >> s;
    int w; cin >> w;
    int n = s.size();
    fill(r, r + n + 5, 0);
    fill(l, l + n + 5, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            cnt_l[i + 1] = cnt_l[i];
            
        }
        else {
            cnt_l[i + 1] = cnt_l[i] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '.') {
            cnt_r[i] = cnt_r[i + 1];
        }
        else {
            cnt_r[i] = cnt_r[i  + 1] + 1;
        }
    }
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < n) {
        while (j < n && cnt < w) {
            if (s[j] == '.') cnt++;
            j++;
        }
        if (cnt == w) {

        }
    }
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}   