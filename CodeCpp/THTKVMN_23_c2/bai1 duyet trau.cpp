#include<bits/stdc++.h>
#define ll long long;
#define ld long double;
using namespace std;

void solve()
{
    string s; cin >> s;
    int n = s.size(), diff = 0;
    vector<char> res1(0), res2(0);
    for (int i = n - 1; i >= 0; i--) {
        if (diff == 0) {
            if ((s[i] - '0') % 2 != 0) {
                res1.push_back(char((s[i] - '0') / 2 + '1'));
                res2.push_back(char((s[i] - '0') / 2 + '0'));
                diff += 1;
            } else {
                res1.push_back(char((s[i] - '0') / 2 + '0'));
                res2.push_back(char((s[i] - '0') / 2 + '0'));
            }
        } else if (diff == 1) {
            if (s[i] == '0') {

            } else {
                if ((s[i] - '0') % 2 == 0) {

                } else {
                    
                }
            }
        } else if (diff == -1) {
            
        }
    }
    if (diff != 0) cout << -1 << endl;
    else {
        while (res1.back() == '0') res1.pop_back();
        while (res2.back() == '0') res2.pop_back();
        for (int i = res1.size() - 1; i >= 0; i--)
            cout << res1[i];
        cout << ' ';
        for (int i = res2.size() - 1; i >= 0; i--)
            cout << res2[i];
        cout << endl;
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