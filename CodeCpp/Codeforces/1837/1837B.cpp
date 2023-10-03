#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; string s;
    cin >> n >> s;
    int cnt = 0, ma = 0, mi = 0;
    char pre = '0';
    for (int i = 0; i < n; i++) {
        if (s[i] == '>')
            cnt--;
        else
            cnt = 0;
        mi = min(mi, cnt);
    }
    cnt = mi;
    for (int i = 0; i < n; i++) {
        if (s[i] == '<')
            cnt++;
        else 
            cnt = mi;
        ma = max(ma, cnt);
    }
    cout << ma - mi + 1 << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}