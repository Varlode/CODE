#include<bits/stdc++.h>
using namespace std;

string s;

int process(int l, int r)
{
    int pre = 0, ans = 0;
    for (int i = l; i <= r; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            ans += pre*(s[i]-'0'); pre = 0;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            ans += pre; pre = 0;
            if (s[i] == 'H') pre = 1;
            if (s[i] == 'C') pre = 12;
            if (s[i] == 'O') pre = 16;
        }
        else
        {
            ans += pre; pre = 0;
            int cnt = 1;
            for (int j = i+1; j <= r; j++)
            {
                if (s[j] == '(') cnt++;
                else if (s[j] == ')') cnt--;
                if (cnt == 0)
                {
                    pre = process(i+1, j-1);
                    i = j;
                    break;
                }
            }
        }
    }
    return ans + pre;
}

void solve()
{
    cin >> s;
    cout << process(0, s.size()-1);
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
//    cin >> Test;
    while (Test--)
    {
        solve();
    }
}

