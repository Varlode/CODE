#include<bits/stdc++.h>
using namespace std;

void lis()
{
    int res_lis, x;
    vector<int> a_lis, res;
    while (cin >> x)
    {
        int tmp = lower_bound(a_lis.begin(), a_lis.end(), x) - a_lis.begin();
        if (tmp == a_lis.end() - a_lis.begin())
            a_lis.push_back(x);
        else
            a_lis[tmp] = x;
        if (res_lis < tmp)
        {
            res_lis = tmp;
            res.clear();
            for (int i = 0; i < tmp; i++)
                res.push_back(a_lis[i]);
        }
    }
    for (int i : res)
        cout << i << " ";
    
}

//---------------------------------------------------------------- 1

int a_lcs[1005], b_lcs[1005], c_lcs[1005][1005];

void lcs()
{
    int n, m, max_lcs = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a_lcs[i];
    for (int i = 1; i <= m; i++)
        cin >> b_lcs[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            c_lcs[i][j] = max(
                max(
                    c_lcs[i - 1][j],
                    c_lcs[i][j - 1]
                ),
                c_lcs[i - 1][j - 1] + (a_lcs[i] == b_lcs[j])
            );
            max_lcs = max(max_lcs, c_lcs[i][j]);
        }
    cout << max_lcs << endl;
    vector<int> res;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a_lcs[i] == b_lcs[j])
        {
            res.push_back(a_lcs[i]);
            i--; j--;
        } 
        else if (c_lcs[i][j] == c_lcs[i - 1][j]) i--; 
        else j--;
    }
    i = res.size();
    while (i--) cout << res[i] << " ";
}

//---------------------------------------------------------------- 2

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    lcs();
}