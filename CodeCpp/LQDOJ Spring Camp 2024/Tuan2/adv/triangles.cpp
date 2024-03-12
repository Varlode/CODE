#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n, a[N];
pair<int, int> b[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);

    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i-1]) b[cnt].second++;
        else
        {
            ++cnt;
            b[cnt].first = a[i];
            b[cnt].second = 1;
        }
    }

    n = cnt;

    for (int i = 1; i <= n; i++)
    {
        if (b[i].second >= 3) ans++;
    }

    int k = 2;
    for (int i = 1; i <= n; i++)
    {
        while (k <= n && b[i].first*2 > b[k].first) k++;
        if (b[i].second >= 2)
        {
            ans += k-2;
        }
    }

    for (int j = 2; j <= n; j++)
    {
        int l = j, r = j+1;
        for (int i = 1; i < j; i++)
        {
            while (r <= n && b[i].first+b[j].first > b[r].first) r++;
            while (l <= n && b[l].first <= b[j].first-b[i].first) l++;
            ans += r-l;
            if (r-l) {
                if (l <= i && i < r) ans--;
                if (l <= j && j < r) ans--;
            }
        }
    }
    cout << ans;
}

int main()
{
    #define task "TASK"
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
//    cin >> t;
    while (t--)
    {
        solve();
    }
}
