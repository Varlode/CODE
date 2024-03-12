#include<bits/stdc++.h>
using namespace std;

string s;
vector<char> bracket_in;

bool is_bracket_in(char c)
{
    if (c == '(') return true;
    if (c == '{') return true;
    if (c == '[') return true;
    return false;
}

char change_to_in(char c)
{
    if (c == ')') return '(';
    if (c == '}') return '{';
    if (c == ']') return '[';
    return 0;
}

void solve()
{
    bracket_in.clear();
    cin >> s;
    for (char c: s)
    {
        if (is_bracket_in(c))
            bracket_in.push_back(c);
        else
            if (bracket_in.size() && bracket_in.back() == change_to_in(c))
                bracket_in.pop_back();
            else
            {
                cout << "NO\n";
                return;
            }
    }
    if (bracket_in.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
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
    cin >> Test;
    while (Test--)
    {
        solve();
    }
}
