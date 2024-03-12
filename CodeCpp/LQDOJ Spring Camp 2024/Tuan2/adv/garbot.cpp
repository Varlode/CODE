#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6+1;
int m_robot, n_rac, pos_robot[N], pos_rac[N];

bool check(int m)
{
    int l_rac = 1, r_rac = 1;
    for (int id_robot = 1; id_robot <= m_robot; id_robot++)
    {
        if (abs(pos_robot[id_robot] - pos_rac[l_rac]) > m) continue;

        while (r_rac <= n_rac)
        {
            int cost = 0;
            if (pos_rac[l_rac] >= pos_robot[id_robot])
            {
                cost = pos_rac[r_rac] - pos_robot[id_robot];
            }
            else if (pos_rac[r_rac] >= pos_robot[id_robot])
            {
                cost = min(
                    pos_rac[r_rac] - pos_robot[id_robot],
                    pos_robot[id_robot] - pos_rac[l_rac])
                + pos_rac[r_rac] - pos_rac[l_rac];
            }
            else
            {
                cost = pos_robot[id_robot] - pos_rac[l_rac];
            }

            if (cost > m)
            {
                l_rac = r_rac;
                break;
            }
            r_rac++;
        }
    }
    return r_rac > n_rac;
}

void solve()
{
    cin >> m_robot >> n_rac;
    for (int i = 1; i <= m_robot; i++) cin >> pos_robot[i];
    sort(pos_robot+1, pos_robot+1+m_robot);
    for (int i = 1; i <= n_rac; i++) cin >> pos_rac[i];
    sort(pos_rac+1, pos_rac+1+n_rac);

    int l = 0, r = 4e9, ans = 0;
    while (l <= r)
    {
        int m = (r + l) >> 1;
        if (check(m))
        {
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    cout << ans;
}

main()
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
