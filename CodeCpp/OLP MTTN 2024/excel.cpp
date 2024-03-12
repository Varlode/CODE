#include<bits/stdc++.h>
using namespace std;

int n, m, a[30][30], q;
string s;

int process(int l, int r)
{
    string query;

    int i = l;
    while (i <= r && 'A' <= s[i] && s[i] <= 'Z')
    {
        query.push_back(s[i]);
        i++;
    }

    if (query.size() < 3)
    {
        int result = a[s[r]-'0'][s[l]-'A'];
        return result;
    }
    int bracket = i, cnt_bracket = 0;
    int comma = i+1 ;
    while (comma <= r && (s[comma] != ',' || cnt_bracket > 0))
    {
        if (s[comma] == '(') cnt_bracket++;
        if (s[comma] == ',') cnt_bracket--;
        comma++;
    }
    if (query == "MAX")
    {
        return max(process(bracket+1, comma-1), process(comma+1, r-1));
    }
    else
    {
        return process(bracket+1, comma-1) + process(comma+1, r-1);
    }
}

void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> q;
    while (q--)
    {
        cin >> s;
        cout << process(0, (int)s.size()-1) << '\n';
    }
}

int main()
{
    #define task "TASK"
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int Test = 1;
    // cin >> Test;
    while (Test--)
    {
        solve();
    }
}
