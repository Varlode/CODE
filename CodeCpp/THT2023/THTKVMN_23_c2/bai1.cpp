#include<bits/stdc++.h>
#define ll long long;
#define ld long double;
using namespace std;

int num(char c) {
    return (c - '0');
}

void solve()
{
    int n; cin >> n;
    int res1, res2;
    res1 = res2 = n / 2;
    string s, s1, s2;
    s = to_string(n);
    s1 = to_string(res1);
    s2 = to_string(res2);
    while (s2.size() < s1.size()) s2 = '0' + s2;
    while (s2.size() > s1.size()) s1 = '0' + s1;
    int mem = 0, flag = 1, diff = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        int tmp1 = num(s1[i]), tmp2 = num(s2[i]), tmp = num(s[i]);
        if (tmp1 + tmp2 > tmp - mem) {
            tmp += 10;
            mem = 1;
        }
        if (mem == 1) {
            if (diff >= 0) {
                s2[i] = char(tmp / 2 + 1 + '0');
                diff -= 1;
            } if (diff == 1) {
                s1[i] = char(tmp / 2 + 1 + '0');
                diff = 0;
            }
            continue;
        }
        if (tmp1 + tmp2 == tmp - mem) {
            mem = 0;
            continue;
        }
        if (tmp1 + tmp2 < tmp - mem) {
            if (diff >= 0) {
                s2[i] = char(tmp / 2 + 1 + '0');
                diff -= 1;
            } if (diff == 1) {
                s1[i] = char(tmp / 2 + 1 + '0');
                diff = 0;
            }
            mem = 0;
            continue;
        }
    }
    cout << s1 << ' ' << s2 << endl;
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