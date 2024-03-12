#include<bits/stdc++.h>
using namespace std;

#define pii pair<long long, int>
const int N = 1e6+10;
int n, m, k;
int thuan_way[N];
long long d[N];
vector<pii> adj[N];

void dijkstra(int u)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[u] = 0;
    pq.push(pii(0, u));
    while (!pq.empty())
    {
        u = pq.top().second; pq.pop();
        for (pii p: adj[u])
        {
            int v = p.first, w = p.second;
            if (d[u]+w < d[v])
            {
                d[v] = d[u]+w;
                pq.push(pii(d[v], v));
            }
        }
        while (!pq.empty() && pq.top().first < d[pq.top().second])
            pq.pop();
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> thuan_way[i];

    for (int i = 1; i <= n; i++) d[i] = 1e18;
    dijkstra(thuan_way[k]);
    int minimum = 0, maximum = 0;
    for (int i = 1; i < k; i++)
    {
        int u = thuan_way[i], cnt = 0, nxt = 0, v_w = 0;
        long long mn = 1e18;
        for (auto p: adj[u])
        {
            int v = p.first, w = p.second;
            if (mn > d[v]+w)
            {
                mn = d[v]+w;
                cnt = 1;
            }
            else if (mn == d[v]+w) cnt++;
            if (v == thuan_way[i+1]) v_w = w;
        }
        if (cnt == 1 && d[thuan_way[i+1]]+v_w != mn)
        {
            minimum++;
            maximum++;
        }
        else if (cnt > 1)
        {
            maximum++;
            if (d[thuan_way[i+1]]+v_w != mn) minimum++;
        }
    }
    cout << minimum << ' ' << maximum;
}

main()
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
