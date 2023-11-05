#include <bits/stdc++.h>
using namespace std;

const int N = 10100;

int n;
string s;

int child[N][2], dpMx[N][2], dpMn[N][2];

void dfs(int u, int isRed) {
    if (u == n) return;
    if (dpMx[u][isRed] != -1) return;
    int child1 = child[u][0], child2 = child[u][1];
    if (isRed) {
        if (s[u] == '0') 
            dpMx[u][1] = dpMn[u][1] = 1;
        else if (s[u] == '1') {
            dfs(child1, 0);
            dpMx[u][1] = dpMx[child1][0]+1;
            dpMn[u][1] = dpMn[child1][0]+1;
        } else {
            dfs(child1, 0);
            dfs(child2, 0);
            dpMx[u][1] = dpMx[child1][0] + dpMx[child2][0] + 1;
            dpMn[u][1] = dpMn[child1][0] + dpMn[child2][0] + 1;
        }
    } else {
        if (s[u] == '0') 
            dpMx[u][0] = dpMn[u][0] = 0;
        else if (s[u] == '1') {
            dfs(child1, 0);
            dfs(child1, 1);
            dpMx[u][0] = max(dpMx[child1][0], dpMx[child1][1]);
            dpMn[u][0] = min(dpMn[child1][0], dpMn[child1][1]);
        } else {
            dfs(child1, 0);
            dfs(child1, 1);
            dfs(child2, 0);
            dfs(child2, 1);
            dpMx[u][0] = max(
                dpMx[child1][0] + dpMx[child2][1],
                dpMx[child1][1] + dpMx[child2][0]
            );
            dpMn[u][0] = min(
                dpMn[child1][0] + dpMn[child2][1],
                dpMn[child1][1] + dpMn[child2][0]
            );
        }
    }
}

int node = 0;
void build() {
    if (node == n) return;
    int cur = node;
    node++; 
    if (s[cur] == '1') {
        child[cur][0] = node;
        build();
    } else if (s[cur] == '2') {
        child[cur][0] = node;
        build();
        child[cur][1] = node;
        build();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "tro"        
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);   
    cin >> s;
    n = s.size();
    memset(dpMx, -1, sizeof dpMx);
    build();
    dfs(0, 0);
    dfs(0, 1);
    cout << max(dpMx[0][0], dpMx[0][1]) << ' ' << min(dpMn[0][0], dpMn[0][1]);
}