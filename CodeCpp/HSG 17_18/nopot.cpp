#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+9;
int T, n, m, q;

void dijkstra(int a) {

}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m >> q;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int> >,
            greater<pair<int, int> >
        > pq;
        vector<int> adj[n+9], e[n+9], id[n+9];
        int x[n+9], y[n+9], z[n+9], u[n+9];
        int d[n+9], vstd[n+9], t[109], c[109];

        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i] >> z[i];
        for (int i = 1; i <= n; i++) {
            d[i] = 1e9+9;
            vstd[i] = 0;
            u[i] = 0;
        }
        d[1] = 0;
        dijkstra(1);
        int k, s;
        for (int i = 1; i <= q; i++) {
            cin >> k >> s;
            for (int i = 1; i <= s; i++) 
                cin >> t[i] >> c[i];
            for (int i = 1; i <= n; i++) {
                
            }

            for (int i = 1; i <= s; i++)
                u[t[i]] = 0;
        }
    }
}