#include<bits/stdc++.h>
using namespace std;

string st;
void theMaxNum()
{
    // int n, k;
    // cin >> n >> k;
    // string s;
    // for (int i = 1; i <= n; i++)
    //     s = s + to_string(i);
    
    int k;
    string s;
    cin >> s >> k;

    st.push_back(s[0]);
    int cur = 1;

    while (cur < s.length())
    {
        while (st.back() < s[cur] && st.size() > 0 && k > 0)
        {
            st.pop_back();
            k--;
        }
        st.push_back(s[cur]);
        cur++;
    }

    while (k > 0)
    {
        st.pop_back();
        k--;
    }
    cout << st;
}

// URL: https://lqdoj.edu.vn/problem/delnum
//---------------------------------------------------------------- 1

void spaceLess()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string tmp;
    vector<string> v;
    while (ss >> tmp)
        v.push_back(tmp);
    cout << "\n" << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << " " << v[i];
}

// URL: https://lqdoj.edu.vn/problem/str04
//---------------------------------------------------------------- 2

void stringZip()
{
    string s;
    cin >> s;
    int cur1 = 0, cur2 = 1;
    string res;
    while (cur1 < s.length() && cur2 < s.length())
    {
        while (s[cur1] == s[cur2] && cur2 < s.length())
            cur2++;
        if (cur2 - cur1 > 1)
            res += to_string(cur2 - cur1) + s[cur1];
        else
            res += s[cur1];
        cur1 = cur2;
    }
    cout << res;
}

// URL: https://lqdoj.edu.vn/problem/comstr
//---------------------------------------------------------------- 3

void pfStr()
{
    string s;
    cin >> s;
    string res = "YES";
    for (int i = 0; i < s.size() - 2; i++)
        if (s[i] == s[i + 1])
        {
            res = "NO";
            break;
        }
    cout << res;
}

// URL: https://lqdoj.edu.vn/problem/hoanhao
//---------------------------------------------------------------- 4

void suaDiem()
{
    int n; cin >> n;
    double sum = 0, m = 100;
    for (int i = 0; i < n; i++)
    {
        double x; cin >> x;
        sum += x;
        m = min(m, x);
    }
    cout << fixed << setprecision(1) << sum - m + 10.0;
}

// URL: https://lqdoj.edu.vn/problem/swcsuadiem
//---------------------------------------------------------------- 5

void palinStr()
{
    string s;
    while (cin >> s)
    {
        int cnt = 0;
        for (int i = 0; i < s.size() / 2 + 1; i++)
            cnt += (s[i] != s[s.size() - 1 - i]);
        if (cnt <= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}

// URL: https://lqdoj.edu.vn/problem/palinstr01
//---------------------------------------------------------------- 6

long long a[1000000];

void pfLR()
{
    int l, r;
    cin >> l >> r;
    int res = 0;

    for (int i = 1; i <= r; i++)
        for (int j = i; j <= r; j += i)
            a[j] += i;

    for (int i = l; i <= r; i++)
        if (a[i] - i > i) res++;
    cout << res;
}

// URL: https://lqdoj.edu.vn/problem/nkabd
//---------------------------------------------------------------- 7

void diemDanh()
{
    int n, m;
    cin >> n >> m;
    vector<bool> a(n + 1, true);
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        a[x] = false;
    }
    int i = 1;
    while (!a[i]) i++;
    cout << i;
    for (int j = i + 1; j <= n; j++)
        if (a[j]) cout << " " << j;
}

// URL: https://lqdoj.edu.vn/problem/swcabsence
//---------------------------------------------------------------- 8

void simpleLove()
{
    int n; cin >> n;
    cout << n * (n + 1) / 2 - 4 * (n / 2 * (n / 2 + 1) / 2) << "\n";
}

// URL: https://lqdoj.edu.vn/problem/easysum
//---------------------------------------------------------------- 9

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
    simpleLove();
}