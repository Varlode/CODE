#include<bits/stdc++.h>
using namespace std;

pair<int, int> a[1000];

void solve()
{
    int n; cin >> n;
    int i = 2, cnt = 0;
    while (i * i <= n)
    {
        int tmp = 0;
        while (n % i == 0)
        {
            tmp++;
            n /= i;
        }
        if (tmp)
        {
            a[cnt] = make_pair(tmp, i);
            cnt++;
        }
        i++;
    }
    if (n != 1) {a[cnt] = make_pair(1, n); cnt++;}
    sort(a, a + cnt);
    vector<int> mult(cnt + 1);
    int res = 0, power = 0, tmp = 1;
    for (int i = cnt - 1; i >= 0; i--)
    {
        tmp *= a[i].second;
        mult[i] = tmp;
    }
    res += mult[0] * a[0].first;
    for (int i = 1; i < cnt; i++) if (a[i].first != a[i - 1].first)
        res += mult[i] * (a[i].first - a[i - 1].first);
    cout << res << endl;
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