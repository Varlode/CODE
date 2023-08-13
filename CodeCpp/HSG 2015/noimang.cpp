#include<bits/stdc++.h>
using namespace std;

const int maxN=1e3+9;
int n, m, x, e[maxN][maxN], id[maxN], vstd[maxN];
long long ans = 0;
vector<int> lt;
priority_queue<
    pair<int, int>,
    vector<pair<int, int> >,
    greater<pair<int, int> > 
> pq;

void dijkstra(int a) {
    vstd[a] = 1;
    
    for (int i = 0; i < lt.size(); i++) if (vstd[lt[i]] == 0) {
        pq.push(make_pair(e[a][lt[i]], lt[i]));
    }

    while (pq.size() && vstd[pq.top().second]) pq.pop(); if (pq.empty()) return;
    pair<int, int> tmp = pq.top(); pq.pop();
    ans += tmp.first;
    dijkstra(tmp.second);
}

void lienthong(int a, int b) {
    if (b < a) swap(a, b);
    if (id[a] == id[b]) return;
    for (int i = 1; i <= n; i++) {
        if (id[i] == id[b]) id[i] = id[a];
    }
}

int main() {
    freopen("noimang.inp", "r", stdin);
    freopen("noimang.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) id[i] = i;

    for (int i = 1; i<=m; i++) {
        int x, y; 
        cin >> x >> y;
        lienthong(x, y);
    }
    for (int i = 1; i <= n; i++) if (id[i] == i) lt.push_back(i);

    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << id[i] << ' '; cout << endl;
    // for (int i = 0; i < lt.size(); i++) cout << lt[i] << ' '; cout << endl;
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (e[id[i]][id[j]] == 0) e[id[i]][id[j]]=x;
            e[id[i]][id[j]] = min(e[id[i]][id[j]], x);
        }
    }

    // cout << endl;
    // for (int i = 0; i < lt.size(); i++) {
    //     for (int j = 0; j < lt.size(); j++) {
    //         cout << e[lt[i]][lt[j]] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    dijkstra(lt[0]);
    cout << ans;
}