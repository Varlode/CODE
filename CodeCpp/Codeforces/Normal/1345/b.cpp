#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    int n = s.size();
    int curr1 = 0, curr2 = 0, ans = 1e9, cnt[4] = {0, 0, 0, 0};
    while (curr1 < n && curr2 < n)
    {
        while (curr2 < n && (cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0))
            cnt[s[curr2++] - '0']++;
        while (curr1 < curr2 && cnt[s[curr1] - '0'] > 1)
            cnt[s[curr1++] - '0']--;
        if (cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0) 
            ans = min(ans, curr2 - curr1);
        cnt[s[curr1++] - '0']--;
        
    }
    if (ans == 1e9) cout << 0 << endl;
    else cout << ans << endl;
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